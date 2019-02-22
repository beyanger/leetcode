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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<int> cr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            for (int qs = q.size(); qs > 0; qs--) {
                root = q.front(); q.pop();
                cr.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back(move(cr));
        }
        return ans;
    }
};

