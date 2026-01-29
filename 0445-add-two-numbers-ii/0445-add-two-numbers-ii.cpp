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
    ListNode* reverse(ListNode* l1){
        ListNode* nxtnode = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = l1;
        while(curr!=nullptr){
            nxtnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxtnode;
        }
        return prev;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dumhead = dummy;
        int carry =0;
        while(curr1 && curr2){
            int value = curr1->val + curr2->val + carry;
            carry  = value/10;
            value %= 10;
            ListNode* valnode = new ListNode(value);
            dumhead->next = valnode;
            dumhead = dumhead->next;
            curr1= curr1->next;
            curr2= curr2->next;
        }
        while(curr1){
            int value = curr1->val + carry;
            carry  = value/10;
            value %= 10;
            ListNode* valnode = new ListNode(value);
            dumhead->next = valnode;
            dumhead = dumhead->next;
            curr1= curr1->next;
        }
        while(curr2){
            int value = curr2->val + carry;
            carry  = value/10;
            value %= 10;
            ListNode* valnode = new ListNode(value);
            dumhead->next = valnode;
            dumhead = dumhead->next;
            curr2= curr2->next;
        }
        if(carry!=0){
            ListNode* valnode = new ListNode(carry);
            dumhead->next = valnode;
            dumhead = dumhead->next;
        }
        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = add(l1,l2);
        return reverse(ans);
    }
};