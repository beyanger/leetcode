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

	void check(TreeNode *root, TreeNode *&prev, TreeNode *& t1, TreeNode *& t2) {
		if (!root) return;
		check(root->left, prev, t1, t2);

		if (prev && prev->val > root->val) {
			if (!t1) t1 = prev;
			t2 = root;
		}
		prev = root;

		check(root->right, prev, t1, t2);
	}

public:
	void recoverTree(TreeNode* root) {
		TreeNode *prev = 0, *t1 = 0, *t2  = 0;
		check(root, prev, t1, t2);
		if (t1 && t2) {
			swap(t1->val, t2->val);
		}
	}
};
