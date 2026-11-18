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
    void inorder(TreeNode* root, vector<int> &bst) {
        if (root->left)
            inorder(root->left, bst);
        
        bst.push_back(root->val);

        if (root->right)
            inorder(root->right, bst);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> bst;

        inorder(root, bst);

        // check if bst elements are sorted
        // because inorder of a valid bst is always sorted

        for (int i = 0; i < bst.size()-1; i++)
            if (bst[i] >= bst[i+1])
                return false;

        return true;
    }
};

/******* OPTIMAL SOLUTION *******/

class SolutionOptimal {
public:
    bool validate(TreeNode* node, long long low, long long high) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;

        return validate(node->left, low, node->val) && 
               validate(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
