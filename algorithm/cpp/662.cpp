
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int left = q.front().second, right = left;
            for (int qs = (int)q.size(); qs > 0; qs--) {
                root = q.front().first;
                right = q.front().second; q.pop();
                if (root->left) q.push({root->left, right*2});
                if (root->right) q.push({root->right, right*2+1});
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};

