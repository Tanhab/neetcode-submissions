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
    TreeNode* helper(TreeNode* root, TreeNode* other){
        if(other == nullptr ) return nullptr;
        root = new TreeNode(other->val);
        root->left = helper(root->left, other->right);
        root->right = helper(root->right, other->left);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return helper(nullptr, root);
    }
};
