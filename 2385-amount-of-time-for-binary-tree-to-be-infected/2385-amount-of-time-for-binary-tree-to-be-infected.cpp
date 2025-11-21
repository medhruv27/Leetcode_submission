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
    void bfstomap(unordered_map<TreeNode*,TreeNode*>&mp,int start,TreeNode* node,TreeNode* &s){
        if(node==NULL) return ;
        if(node->val==start){
            s = node;
        }
        if(node->left){
            mp[node->left]= node;
            bfstomap(mp,start,node->left,s);
        }
        if(node->right){
            mp[node->right] = node;
            bfstomap(mp,start,node->right,s);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
      unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = nullptr;
        bfstomap(parentMap, start, root, startNode);
        int maxTime = 0;
        unordered_set<TreeNode*> visited;  // To avoid reprocessing nodes
        queue<pair<TreeNode*, int>> q;
        q.push({startNode, 0});
        visited.insert(startNode);
        while (!q.empty()) {
            auto [node, currentTime] = q.front();
            q.pop();
            maxTime = max(maxTime, currentTime);

            // Explore children and parent
            if (node->left && visited.find(node->left) == visited.end()) {
                q.push({node->left, currentTime + 1});
                visited.insert(node->left);
            }
            if (node->right && visited.find(node->right) == visited.end()) {
                q.push({node->right, currentTime + 1});
                visited.insert(node->right);
            }
            if (parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()) {
                q.push({parentMap[node], currentTime + 1});
                visited.insert(parentMap[node]);
            }
        }
        return maxTime;
    }
};