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
    vector<vector<int>> level;
    void helper(TreeNode* root, int lvl){
        if(!root) return;
        if(level.size() == lvl) level.push_back({root->val});
        else level[lvl].push_back(root->val);
        helper(root->left, lvl+1);
        helper(root->right, lvl + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return level;
    }
};
