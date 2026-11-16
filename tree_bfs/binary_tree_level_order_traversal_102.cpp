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

/* My Solution */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // if tree is empty
        if(!root)  
            return {};

        // if tree only has root
        if (!root->left && !root->right)
            return {{root->val}};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            // stores all nodes of the same level
            vector<int> v; 
            queue<TreeNode*> temp = q;

            // get all nodes of the current level
            while(!temp.empty()) {
                v.push_back(temp.front()->val);
                temp.pop();
            }

            // update queue with all nodes of next level
            while(!q.empty()) {
                if (q.front()->left)
                    temp.push(q.front()->left);
                if (q.front()->right)
                    temp.push(q.front()->right);
                q.pop();
            }
            
            q = temp;
            res.push_back(v);
        }        

        return res;
    }
};

/* Optimal Solution */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // if tree is empty
        if(!root)
            return {};

        // if tree only has root
        if (!root->left && !root->right)
            return {{root->val}};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            // stores all nodes of the same level
            vector<int> v;
            int len = q.size();

            while(len--) {
                TreeNode* curr = q.front();
                v.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                q.pop();
            }

            res.push_back(v);
        }

        return res;
    }
};
