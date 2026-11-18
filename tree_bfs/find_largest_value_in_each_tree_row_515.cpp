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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};

        vector<int> res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int maxVal = INT_MIN;
            int len = q.size();

            while(len--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                // check if greater than current max
                maxVal = max(maxVal, curr->val);
            }

            res.push_back(maxVal);
        }

        return res;
    }
};
