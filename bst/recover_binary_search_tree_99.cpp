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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* curr) {
        if (!curr)
            return;

        inorder(curr->left);

        // since inorder traverses in an array format
        // if we find an element that is greater than the next element
        // we mark that element for swap.

        // 2 cases
        // either two elements to be swapped are adjacent or not
        // hence assuming they might be adjacent, we update both "first" and "second"
        if (prev && prev->val > curr->val) {
            if (!first) first = prev;
            second = curr;
        }
        prev = curr;

        inorder(curr->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
