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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<int> cr;
        queue<TreeNode *> q; q.push(root);
        bool reve = false;
        while (!q.empty()) {
            for (int qs = q.size(); qs > 0; qs--) {
                root = q.front(); q.pop();
                cr.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (reve) reverse(cr.begin(), cr.end());
            reve = !reve;
            ans.push_back(move(cr));
        }
        return ans;
    }
};
