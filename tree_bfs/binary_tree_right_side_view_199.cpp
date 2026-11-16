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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        stack<int> st;

        // push root initially
        q.push(root);
        res.push_back(root->val);
        
        while(!q.empty()) {
            int len = q.size();

            while(len--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) {
                    q.push(curr->left);
                    st.push(curr->left->val);
                }
                if (curr->right) {
                    q.push(curr->right);
                    st.push(curr->right->val);
                }
            }

            if (!st.empty())
                res.push_back(st.top());

            while(!st.empty())
                st.pop();
        }

        return res;
    }
};
