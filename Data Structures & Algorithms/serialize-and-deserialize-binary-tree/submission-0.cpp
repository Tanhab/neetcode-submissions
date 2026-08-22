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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(!n) {
                s+= "#,";
                continue;
            }
            s += to_string(n->val) + ",";
            q.push(n->left);
            q.push(n->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        getline(ss,s,',');
        if(s=="#") return nullptr;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);
        while(getline(ss,s,',')){
            TreeNode* node = q.front();
            q.pop();
            if(s != "#"){
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }
            getline(ss,s,',');
            if(s!= "#"){
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }
        return root; 
    }
};
