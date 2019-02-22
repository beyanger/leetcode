
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode *> sk;
        sk.push(root); 
        sk.push(root);
        while (!sk.empty()) {
            root = sk.top(); sk.pop();
            if (!sk.empty() && root == sk.top()) {
                if (root->right) {
                    sk.push(root->right); 
                    sk.push(root->right);
                }
                if (root->left) {
                    sk.push(root->left);
                    sk.push(root->left);
                }
            } else ans.push_back(root->val);
        }
        return ans;
    }
};
