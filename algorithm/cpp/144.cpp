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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> sk;

        while (root) {
            while (root) {
                ans.push_back(root->val);
                if (root->right) sk.push(root->right);
                root = root->left;
            }
            if (!sk.empty()) {
                root = sk.top();
                sk.pop();
            }
        }
        return ans;
    }
};


