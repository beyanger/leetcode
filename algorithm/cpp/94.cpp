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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> sk;
        while (root) {
            while (root) {
                sk.push(root);
                root = root->left;
            }
            while (!root && !sk.empty()) {
                root = sk.top(); sk.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

