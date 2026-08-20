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
    vector<int> rhs;
    void  helper(TreeNode* root, int lvl){
        if(!root) return;
        if(rhs.size() == lvl) rhs.push_back(root->val);
        else rhs[lvl] = root->val;
        helper(root->left, 1 + lvl);
        helper(root->right, 1 + lvl);
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root,0);
        return rhs;
    }
};
