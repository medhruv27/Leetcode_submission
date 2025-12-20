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
    int mini =INT_MAX;
    int currval=INT_MAX;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        if(currval!=root->val){
            mini = min(mini,abs(currval - root->val));
        }
        currval = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }
};