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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>morris;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                morris.push_back(curr->val);
                curr = curr->right;// 7 ka right 1 fir 4 ka right 2
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev= prev->right;//  7 tak jane kai liye // fir 4 tak jane kai liye 
                }
                if(prev->right==NULL){
                    prev->right = curr; //first time thread ban rha jodo fir aage badho 
                    curr = curr->left;
                }
                else if(prev->right==curr){
                    prev->right=NULL; // ab 2 and 4 vala hoga jisme 2 ka left bhi 
                                       // 4(prev) hai aur 4 ka right bhi 2 hai  
                    morris.push_back(curr->val); // iska matlab tum root pe ho root ko push kiya fir curr kai right gaye fir ye similar chiz kiya
                    curr = curr->right;
                    
                }
                
            }
        }
        return morris;
    }
};