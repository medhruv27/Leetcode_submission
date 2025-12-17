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
    
    TreeNode* solve(vector<int>nums,int s,int e,TreeNode* root){
        if(s>e){
            return nullptr;
        }
        int maxii = -1;
        int maxval = -1;
        for(int i=s;i<=e;i++){
            if(maxval<nums[i]){
                maxval = nums[i];
                maxii = i;
            }
        }
        root = new TreeNode(nums[maxii]);
        root->left = solve(nums,s,maxii-1,root);
        root->right = solve(nums,maxii+1,e,root);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root;
        return solve(nums,0,nums.size()-1,root);
        
    }
};