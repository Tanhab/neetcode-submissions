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
    bool equal(TreeNode* original, TreeNode* other) {
        if (original && !other) return false;
        if(other && !original) return false;
        if (!original) return true;
        if (original->val != other->val) return false;
        return equal(original->left, other->left) && equal(original->right, other->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool b = false;
        if (root->val == subRoot->val) b = equal(subRoot, root);

        return b || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
