/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1;
        vector<TreeNode*> q1;

        TreeNode* temp = root;
        while(temp) {
            if (temp->val == p->val) {
                p1.push_back(temp);
                break;
            }
            
            p1.push_back(temp);
            if (p->val > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }

        temp = root;
        while(temp) {
            if (temp->val == q->val) {
                q1.push_back(temp);
                break;
            }
            
            q1.push_back(temp);
            if (q->val > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }

        TreeNode* result = nullptr;
        int i = 0, j = 0;
        while(i < p1.size() && j < q1.size() && p1[i]->val == q1[j]->val) {
            result = p1[i];
            i++; j++;
        }

        return result;
    }
};

/** OPTIMAL SOLUTION **/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr) {
            if (curr->val > p->val && curr->val > q->val)
                curr = curr->left;
            else if (curr->val < p->val && curr->val < q->val)
                curr = curr->right;
            else
                return curr;
        }

        return curr;
    }
};
