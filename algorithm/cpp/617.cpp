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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == 0 && t2 == 0) return 0;

		TreeNode *t1l, *t1r, *t2l, *t2r;
		int val = 0;
		if (t1) {
			val += t1->val; t1l = t1->left; t1r = t1->right;
		} else {
			t1l = t1r = 0;
		}
		if (t2) {
			val += t2->val; t2l = t2->left; t2r = t2->right;
		} else {
			t2l = t2r = 0;
		}
		TreeNode *node = new TreeNode(val);
		node->left = mergeTrees(t1l, t2l);
		node->right = mergeTrees(t1r, t2r);
		return node;
	}
};
