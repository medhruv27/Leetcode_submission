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
    vector<int>ans;
    bool issmall(vector<int>temp){
        int t = temp.size();
        int a = ans.size();
        int i=0;
        while(i<t && i<a){
            if(temp[i]>ans[i]){
                return false;
            }else if(temp[i]==ans[i]){
                i++; continue;
            }else{
                return true;
            }
        }
        if(i==a){
            return false;
        }
        return true;
    }
    void solve(TreeNode* node,vector<int> temp){
        if(node==NULL){
            return;
        }
        if(node->left==NULL && node->right==NULL){
            temp.push_back(node->val);
            reverse(temp.begin(),temp.end());
            if(ans.empty() || issmall(temp)){
                ans = temp;
            }
            return;
        }
        temp.push_back(node->val);
        solve(node->left,temp);
        solve(node->right,temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<int>temp;
        solve(root,temp);
        string res = "";
        for(auto it : ans){
            res += (it+'a');
            cout<<it<<endl;
        }
        return res;
    }
};