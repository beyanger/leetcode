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
        if (!root) return {};
        vector<vector<int>> res;
        vector<TreeNode *> le;
        le.push_back(root);
        while (le.size() > 0) {
            vector<int> l;
            vector<TreeNode *> ne;
            for (auto node : le) {
                l.push_back(node->val);
                if (node->left) ne.push_back(node->left);
                if (node->right) ne.push_back(node->right);
            }
            res.push_back(l);
            le = ne;
        }
        return res;
    }
};

class Solution {
    void helper(TreeNode* node, int height, vector<vector<int>>& dp) {
        if (!node) return;
        if (height >= dp.size()) dp.push_back({});
        dp[height].push_back(node->val);
        helper(node->left, height+1, dp);
        helper(node->right, height+1, dp);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }
};
