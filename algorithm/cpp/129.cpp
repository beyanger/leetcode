
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
    int ans = 0;

    int sumNumbers(TreeNode *root, int cr) {
        if (!root) return ans;
        int pv = cr * 10 + root->val;
        if (!root->left && !root->right) {
            return ans += pv;
        }
        if (root->left) sumNumbers(root->left, pv);
        if (root->right) sumNumbers(root->right, pv);
        return ans;
    }

public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};
