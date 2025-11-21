/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = false;
    void solve(int sum ,TreeNode* root, int t) {
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            sum+= root->val;
            if(sum ==t){
                ans = true;
            }
            return;
        }
        sum+= root->val;
        solve(sum,root->left,t);
        solve(sum,root->right,t);
    }

    bool hasPathSum(TreeNode* root, int t) {
        solve(0,root,t);
        return ans;
    }
};