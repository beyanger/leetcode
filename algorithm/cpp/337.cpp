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
    
    int rob2(TreeNode *root) {
        if (!root) return 0;
        int sa = rob2(root->left), sb = rob2(root->right);
        int as = root->left ? root->left->val : 0;
        int bs = root->right ? root->right->val : 0;
        root->val += sa + sb; // max amount with root
        return max(sa, as) + max(sb, bs); // max amount without root
    }
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        int r = rob2(root);
        return max(r, root->val);
    }
};

