
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
    vector<TreeNode *> generateTrees(int begin, int end) {
        if (begin > end) return {NULL};
        vector<TreeNode *> res;
        for (int i = begin; i <= end; i++) {
            vector<TreeNode *> lv = generateTrees(begin, i-1);
            vector<TreeNode *> rv = generateTrees(i+1, end);
            for (auto l : lv) {
                for (auto r : rv) {
                    auto v = new TreeNode(i);
                    v->left = l;
                    v->right = r;
                    res.push_back(v);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }
};
