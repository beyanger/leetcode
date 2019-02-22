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
    TreeNode *prev = 0, *t1 = 0, *t2  = 0;
    void check(TreeNode *root) {
        if (!root) return;
        check(root->left);
        if (prev && prev->val > root->val) {
            if (!t1) t1 = prev;
            t2 = root;
        }
        prev = root;
        check(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        check(root);
        if (t1 && t2) {
            swap(t1->val, t2->val);
        }
    }
};
