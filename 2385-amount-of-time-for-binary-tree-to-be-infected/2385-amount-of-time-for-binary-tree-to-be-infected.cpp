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
    TreeNode* parent(TreeNode* root,map<TreeNode*,TreeNode*>&mp,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start){
                res = node;
            }
            if(node->left){
                q.push(node->left);
                mp[node->left]= node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]= node;
            }
        }
        return res;
    }
    int solve(map<TreeNode*,TreeNode*>&mp,TreeNode* s){
        if (!s) return 0;
        int maxi =0;
        queue<TreeNode*>q;
        map<TreeNode*,bool>vis;
        vis[s] = true;
        q.push(s);
        while(!q.empty()){

            int f = 0;
            int n = q.size();
            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                 if (node->left != nullptr && vis.find(node->left) == vis.end()) {
                f = 1;
                vis[node->left] = true;
                q.push(node->left);
                }
                if (node->right != nullptr && vis.find(node->right) == vis.end()) {
                    f = 1;
                    vis[node->right] = true;
                    q.push(node->right);
                }            
                if (mp.count(node) && vis.find(mp[node]) == vis.end()) {
                    f = 1;
                    vis[mp[node]] = true;
                    q.push(mp[node]);
                }
            }
            if(f==1){
                maxi++;
            }
        }
        return maxi;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        TreeNode* s = parent(root,mp,start);
        return solve(mp,s);
    }
};