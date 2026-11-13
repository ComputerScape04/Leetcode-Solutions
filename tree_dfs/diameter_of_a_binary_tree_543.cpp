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
    int diameter(TreeNode* node, int *result) {
        if (!node->left && !node->right)
            return 0;

        int left, right;

        if (node->left) left = diameter(node->left, result) + 1;
        else left = 0;

        if (node->right) right = diameter(node->right, result) + 1;
        else right = 0;

        *result = max(left + right, *result);

        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int ignore = diameter(root, &res);

        return res;
    }
};
