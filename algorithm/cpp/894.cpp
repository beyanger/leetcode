
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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<vector<TreeNode *>> tree(N+1);
        tree[1].push_back(new TreeNode(0));
        for (int i = 3; i <= N; i+=2) {
            for (int j = 1; j < i; j+=2) {
                for (auto l : tree[j]) {
                    for (auto r : tree[i-j-1]) {
                        TreeNode *rt = new TreeNode(0);
                        rt->left = l; rt->right = r;
                        tree[i].push_back(rt);
                    }
                }
            }
        }
        return tree[N];
    }
};

