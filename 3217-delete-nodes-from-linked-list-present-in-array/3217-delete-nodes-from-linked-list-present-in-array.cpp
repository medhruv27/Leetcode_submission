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
        unordered_set<int>todel;
        for(auto num : nums){
            todel.insert(num);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy ,*curr = head;
        while(curr!=NULL){
            if(todel.count(curr->val)==0){//dont delete kar
                prev->next = curr;
                prev = prev ->next;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return dummy->next;
    }
};