/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return nullptr;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        // if(root->left==nullptr && root->right==NULL){
        //     return nullptr;
        // }
        TreeNode* left = solve(root->left,p,q);
        TreeNode* right = solve(root->right,p,q);
        if((left == p && right==q)||(left == q && right==p)){
            return root;
        }else if(left!=nullptr){
            return left;
        }
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};