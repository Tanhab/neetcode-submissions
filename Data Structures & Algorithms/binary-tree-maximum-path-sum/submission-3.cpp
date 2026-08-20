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
#include <print>

class Solution {
   public:
    int mx = INT_MIN;
    int helper(TreeNode* root) {
        if (!root) return INT_MIN;
        int l = helper(root->left);
        int r = helper(root->right);
        int cur = root->val;
        if (l + cur > cur) cur += l;
        if (r + cur > cur) cur += r;
        mx = max(mx, cur);
        //println("{} {} {} {}", root->val, l, r, mx);
        return max(r , l) + root->val > root->val ? root->val + max(l, r) : root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return mx;
    }
};
