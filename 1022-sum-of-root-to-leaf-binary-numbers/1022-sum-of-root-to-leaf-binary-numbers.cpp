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
    int ans =0;
    int convert(string bin){
        std::bitset<64> b64(bin);
        unsigned long long x64 = b64.to_ullong();
        return x64;
    }
    void solve(TreeNode* node,string temp){
        if(node==NULL){
            return;
        }
        if(node->left==NULL && node->right==NULL){
            temp+= to_string(node->val);
            int sum = convert(temp);
            cout<<temp<<endl;
            ans+= sum;
            return;
        }
        temp+= to_string(node->val);
        solve(node->left,temp);
        solve(node->right,temp);
    }
    int sumRootToLeaf(TreeNode* root) {
            solve(root ,"");
            return ans;
            // return 3;
    }
};