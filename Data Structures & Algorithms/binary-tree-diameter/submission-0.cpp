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
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(1 + height(root->left), 1 + height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int val = height(root->left) + height(root->right);
        return max(val, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};
