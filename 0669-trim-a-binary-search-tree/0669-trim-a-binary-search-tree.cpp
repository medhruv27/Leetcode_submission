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
    TreeNode* trim(TreeNode* &root,long long minval,long long maxval){
        if(root==NULL){
            return NULL;
        }
        if(root->val < minval ){
            return trim(root->right,minval,maxval);
        }
        if(root->val > maxval){
            return trim(root->left,minval,maxval);
        }
        // if(root->val >= minval && root->val <=maxval){
            root->left = trim(root->left,minval,root->val);
            root->right = trim(root->right,root->val,maxval);
        // }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }
};
