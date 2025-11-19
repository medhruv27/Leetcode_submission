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
    pair<int,int>ans;
    pair<int,int> solve(TreeNode* node){
        if(node==NULL){
            return {0,0};
        }
        pair<int,int>left =  solve(node->left);
        pair<int,int>right = solve(node->right);
        ans.first  = node->val + left.second + right.second;
        ans.second = max({left.first, left.second}) + max({right.first, right.second}); 
        return ans;
    }
    int rob(TreeNode* root) {
        ans = {0,0};
        solve(root);
        int res = max(ans.first,ans.second); 
        return res;
    }
};