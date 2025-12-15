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
    map<int,int>mpost;
    vector<int>pre;
    vector<int>post;
    TreeNode* solve(int i1,int i2,int j1,int j2){
        if(i1>i2 || j1>j2){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i1]);
        if(i1!=i2){
            int leftval = pre[i1+1];
            int mid = mpost[leftval];
            int leftsize = mid-j1+1;
            root->left = solve(i1+1,i1+leftsize,j1,mid);
            root->right = solve(i1+leftsize+1,i2,mid+1,j2-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pr, vector<int>& pos) {
        int n = pos.size();
        for(int i=0;i<n;i++){
            mpost[pos[i]] =i;
        }
        pre = pr;
        post = pos;
        return solve(0,n-1,0,n-1);
    }
};