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
    unordered_map<int,vector<int>> v;
    void createGraph(TreeNode* root){
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});
        while(q.size()){
            auto [node,parent]= q.front(); q.pop();
            if(parent!=-1){
                v[parent].push_back(node->val);
                v[node->val].push_back(parent);
            }
            if(node->left)  q.push({node->left,node->val});
            if(node->right) q.push({node->right,node->val});
        }   
    }
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root);
        queue<int> q;
        unordered_map<int,bool> seen;
        q.push(start);
        seen[start]=true;
        int time=0;
        for(;q.size();time++){
            int n= q.size();
            while(n--){
                auto node= q.front();  q.pop();
                for(auto i:v[node]){
                    if(!seen[i]){
                        q.push(i);
                        seen[i]=true;
                    }
                }
            }
        }
        return time-1;
    }
};