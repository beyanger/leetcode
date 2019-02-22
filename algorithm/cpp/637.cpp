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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            long sum = 0;
            int cnt = q.size();
            for (int qs = cnt; qs > 0; qs--) {
                root = q.front(); q.pop();
                sum += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back((double)sum / cnt);
        }
        return res;
    }
};

