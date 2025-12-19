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
    void solve(string &s ,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            s += to_string(root->val) + ',';
            return;
        }
        solve(s,root->left);
        solve(s,root->right);
        return;
    }
    bool leafSimilar(TreeNode* r1, TreeNode* r2) {
        string s1;
        string s2;
        solve(s1,r1);
        solve(s2,r2);
        return (s1==s2);
    }
};