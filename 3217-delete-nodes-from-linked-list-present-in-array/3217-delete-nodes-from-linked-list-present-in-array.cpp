/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        ListNode* dummy  = new ListNode(0);
        ListNode* curr = head;
        ListNode* curr1 = dummy;
        while(curr!=NULL){
            if(mp.find(curr->val)==mp.end()){
                curr1->next = curr;
                curr= curr->next;
                curr1  = curr1->next;
            }else{
                curr = curr->next;
                continue;

            }
        }
        curr1->next  = NULL;
        return dummy->next;

    }
};