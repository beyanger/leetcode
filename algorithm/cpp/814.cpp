
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return 0;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0) 
            return 0;
        return root;
    }
};

