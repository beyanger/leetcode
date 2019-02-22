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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<int> cr;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            for (int qs = q.size(); qs > 0; qs--) {
                TreeNode *rt = q.front(); q.pop();
                cr.emplace_back(rt->val);
                if (rt->left) q.push(rt->left);
                if (rt->right) q.push(rt->right);
            }
            ans.emplace_back(move(cr));
        }
		reverse(ans.begin(), ans.end());
        return ans;
    }
};

