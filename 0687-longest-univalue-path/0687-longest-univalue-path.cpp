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
    int maxi =0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->val,1};
        }
        pair<int,int>l = solve(root->left);
        pair<int,int>r = solve(root->right);
        if(root->val == l.first && root->val == r.first){
            maxi = max(maxi,1 + l.second + r.second);
            return {root->val,1 + max(l.second , r.second)};
        }
        else if(root->val==l.first){
            maxi = max(maxi,1 + l.second);
            return {root->val,1 + l.second};
        }
        else if(root->val==r.first){
            maxi = max(maxi,1 + r.second);
            return {root->val,1 + r.second};
        }
        maxi = max(maxi,1);
        return {root->val,1};
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return (maxi-1)>0?(maxi-1):0;
    }
};