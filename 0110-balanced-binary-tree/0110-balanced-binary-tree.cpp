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
    int solve(TreeNode* node,bool &res){
        if(node == NULL) return 0;
        int l =  solve(node->left,res);
        int r =  solve(node->right,res);
        int temp = 1 + max(l,r);
        if(abs(l - r) > 1){
            res = false;
            return -1;
        }
        return temp;
    }
    bool isBalanced(TreeNode* root) {
        bool res= true;
        solve(root,res);
        return res;
    }
};