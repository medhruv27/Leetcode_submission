/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        queue<TreeNode*>q;
        string ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
           q.pop();
        if (node) {
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            ans += "#,";
        }
    }
    if (!ans.empty()) {
        ans.pop_back();
    }
    return ans;  
     }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if (data.empty() || data == "#") return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root  = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                TreeNode* leftn = new TreeNode(stoi(str));
                node->left = leftn;
                q.push(leftn);
            }
            getline(s,str,',');
            if(str!="#"){
                TreeNode* rightn = new TreeNode(stoi(str));
                node->right = rightn;
                q.push(rightn);
            }
        }
        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));