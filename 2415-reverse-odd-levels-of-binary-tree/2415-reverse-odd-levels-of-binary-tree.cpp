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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*>dq;
        dq.push_back(root);
        bool f = 1;
        while(!dq.empty()){
            auto size = dq.size();
            for(int i=0;i<size/2 && f==0 ;i++){
                swap(dq[i]->val,dq[size-1-i]->val);
            }
            for(int i=0;i<size;i++){
                auto node =dq.front();
                dq.pop_front();
                if(node->left){
                    dq.push_back(node->left);
                }
                if(node->right){
                    dq.push_back(node->right);
                }
            }
            f =!f;
        }
        return root;
    }
};