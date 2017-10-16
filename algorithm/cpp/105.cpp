/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 **/

class Solution {
    typedef vector<int>::iterator ITR;

    TreeNode *buildTree(ITR pb, ITR pe, ITR ib, ITR ie) {
        if (pb >= pe || ib >= ie) return NULL;
        ITR p = find(ib, ie, *pb);
        TreeNode *node = new TreeNode(*pb);
        node->left = buildTree(pb+1, pb+1+distance(ib, p), ib, p);
        node->right = buildTree(pb+1+distance(ib, p), pe, p+1, ie);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
