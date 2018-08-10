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
    bool father(TreeNode *root, TreeNode *target, queue<pair<TreeNode *, bool>>& q) {
        if (root->left) {
            if (root->left == target || father(root->left, target, q)) {
                q.push(make_pair(root, true)); 
                return true;
            }
        }
        if (root->right) {
            if (root->right == target || father(root->right, target, q)) {
                q.push(make_pair(root, false)); 
                return true;
            }
        }
        return false;
    }
    void distance(TreeNode *root, int k, vector<int>& ans) {
        if (!root) return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        queue<TreeNode *> p1, p2;
        queue<TreeNode *> *q1 = &p1, *q2 = &p2;
        TreeNode *top;
        p1.push(root);

        while (!q1->empty()) {
            if (k < 0) return;
            while (!q1->empty()) {
                top = q1->front(), q1->pop();
                if (k > 0) { 
                    if (top->left) q2->push(top->left);
                    if (top->right) q2->push(top->right);
                } else {
                    ans.push_back(top->val);
                }
            }
            k--;
            swap(q1, q2); 
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return {target->val};
        vector<int> ans;
        queue<pair<TreeNode *, bool>> q;
        pair<TreeNode *, bool> top;
        if (root != target)
            father(root, target, q);
        distance(target, K, ans);
        while (!q.empty()) {
            top = q.front(), q.pop();
            K--;
            if (K < 0) break;
            if (K == 0) {
                ans.push_back(top.first->val); break;
            } else {
                if (top.second) distance(top.first->right, K-1, ans);
                else distance(top.first->left, K-1, ans);
            }
        }
       
        return ans;
    }
};
