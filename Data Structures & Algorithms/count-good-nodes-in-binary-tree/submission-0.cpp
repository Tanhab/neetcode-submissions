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
    int helper(TreeNode* root, int mx) {
        if (!root) return 0;
        if (mx <= root->val) {
            return 1 + helper(root->left, root->val) + helper(root->right, root->val);
        }else{
            return helper(root->left, mx) + helper(root->right, mx);
        }
    }
    int goodNodes(TreeNode* root) {
        return helper(root, -101);
    }
};
