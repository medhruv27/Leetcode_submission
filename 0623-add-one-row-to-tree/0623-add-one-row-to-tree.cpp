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
    void solve(TreeNode* &node, int val, int k,int lvl){
        if(lvl==k-1){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            if(node->left!=NULL){
                TreeNode* l1 = node->left;
                l->left = l1;
                node->left = l;
            }
            if(node->right!=NULL){
                TreeNode* r1 = node->right;
                r -> right = r1;
            }
            node->left = l;
            node->right = r;
            return;
        }
        if(node->left){
            solve(node->left,val,k,lvl+1);
        }
        if(node->right){
            solve(node->right,val,k,lvl+1);
        }

    }
    TreeNode* addOneRow(TreeNode* root, int val, int k) {
        if(k==1){
            TreeNode* head = new TreeNode(val);
            head->left = root;
            root = head;
        }
        solve(root,val,k,1);
        return root;
    }
};