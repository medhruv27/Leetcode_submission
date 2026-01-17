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
    string solve(TreeNode* node, string& temp){
        if(node==NULL) return temp;
        temp += to_string(node->val);
        if(node->left==NULL && node->right==NULL){
            return temp;
        }
        if(node->left!=NULL){
            temp += '(';
            solve(node->left,temp);
            temp += ')';
        }
        if(node->left==NULL){
             temp += '(';
             temp += ')';
        }
        if(node->right!=nullptr){
            temp += '(';
            solve(node->right,temp);
            temp += ')';
        }
        return temp;
    }
    string tree2str(TreeNode* root) {
        string temp = "";
        solve(root,temp);
        return temp;
    }
};