
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
    void helper(TreeNode *root, int& sum) {
        if (!root) return;
        if (root->right)helper(root->right, sum);
        root->val = (sum += root->val);
        if (root->left)helper(root->left, sum);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
};

