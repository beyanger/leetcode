
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
    using ITR = vector<int>::iterator;

    TreeNode *buildTree(ITR be, ITR ee, ITR tb, ITR te) {
        if (be >= ee || tb >= te) return nullptr;
        TreeNode *root = new TreeNode(*be);
        be++; te--;
        if (be == ee) return root;
        ITR pos = find(tb, te, *be);
        int dis = (int)distance(tb, pos) + 1;
        root->left = buildTree(be, be+dis, tb, tb+dis);
        root->right = buildTree(be+dis, ee, tb+dis, te);
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return buildTree(pre.begin(), pre.end(), post.begin(), post.end());
    }
};
// 
