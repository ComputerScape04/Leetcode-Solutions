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
    void f(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> v) {
        if (!root)
            return;
        
        v.push_back(root->val);
        if (!root->left && !root->right) {
            if (targetSum == root->val)
                res.push_back(v);
        }

        if (root->left)
            f(root->left, targetSum - root->val, res, v);
        if (root->right)
            f(root->right, targetSum - root->val, res, v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        f(root, targetSum, res, v);

        return res;
    }
};
