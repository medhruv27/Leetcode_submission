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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* h = dummy;
        int carry =0;
        while(c1!=NULL || c2 != NULL){
            int sum  =0;
            if(c1!=NULL){
                sum  += c1->val;
                c1 = c1->next;
            }
            if(c2!=NULL){
                sum  += c2->val;
                c2 = c2->next;
            }
            sum += carry;
            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            h -> next = temp;
            h = h -> next;
        }
        if(carry!=0){
            ListNode* temp = new ListNode(carry%10);
            h -> next = temp;
            h = h -> next;
        }
        return dummy->next;
    }
};