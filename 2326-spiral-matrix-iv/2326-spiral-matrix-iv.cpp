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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        ListNode* curr = head;
        int top =0,bottom=m-1,left =0,right = n-1;
        while(curr!=NULL){
            for(int i=left;i<=right && curr!=NULL;i++){
                res[top][i] = curr->val;
                curr = curr->next;
            }
            top++;
            for(int i=top;i<=bottom && curr!=NULL;i++){
                res[i][right] = curr->val;
                curr = curr->next;
            }
            right--;
            for(int i=right;i>=left && curr!=NULL;i--){
                res[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;            
            for(int i=bottom;i>=top && curr!=NULL;i--){
                res[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        return res;
    }
};