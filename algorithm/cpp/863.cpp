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
    vector<TreeNode *> sibling = {0};
    vector<int> ans;

    bool find_sibling(TreeNode *root, TreeNode *target, int K) {
        if (!root) return false;
        if (root == target) return true;
        bool l = find_sibling(root->left, target, K);
        if (l || find_sibling(root->right, target, K)) {
            if (sibling.size() == K) ans.push_back(root->val);
            sibling.push_back(l ? root->right : root->left);
            return true;
        }
        return false;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return {target->val};
        find_sibling(root, target, K);
        queue<TreeNode *> q;
        q.push(target);
        for (int i = 0, lf = sibling.size(); i < K; i++) {
            for (int qs = q.size(); qs > 0; qs--) {
                root = q.front(); q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (i < lf && sibling[i]) q.push(sibling[i]);
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val); q.pop();
        }
        return ans;
    }
};
