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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr= dummy ;
        while(curr!=NULL && h1!=NULL && h2!=NULL){
            if(h1->val>h2->val){
                curr->next = h2;
                h2 = h2->next;
                curr = curr->next;
            }else{
                curr->next= h1;
                h1 = h1 ->next;
                curr = curr->next;
            }
        }
        while(h1!=NULL){
            curr->next= h1;
            curr = curr->next;
            h1=h1->next;
        }
        while(h2!=NULL){
            curr->next= h2;
            curr = curr->next;
            h2=h2->next;
        }
        return dummy->next;
    }
};