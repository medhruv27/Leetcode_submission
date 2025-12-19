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
    int cnt=0;
    pair<int,int> solve(TreeNode* root,int sum,int n){
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            cnt++;
            return {root->val,1};
        }
        pair<int,int> l= solve(root->left,sum ,n);
        pair<int,int> r= solve(root->right,0,n);
        int avg = (root->val + l.first + r.first)/(1 + l.second + r.second);
        cout<<avg<<endl;
        if(root->val==avg){
            cnt++;
        }
        return {root->val + l.first + r.first,1 + l.second + r.second};

    }
    int averageOfSubtree(TreeNode* root) {
        solve(root,0,0);
        return cnt;
    }
};