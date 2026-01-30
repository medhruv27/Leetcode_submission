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
    struct compare{
        bool operator()(ListNode* a ,ListNode* b){
             return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minh;
        for (ListNode* list : lists) {
            if (list) {
                minh.push(list);
            }
        }
        ListNode * dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!minh.empty()){
            curr->next = minh.top();
            minh.pop();
            curr = curr->next;
            if (curr->next) {
            minh.push(curr->next);
            }
        }
        return dummy->next;
    }
};