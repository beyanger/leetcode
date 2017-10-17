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
	void flatten(TreeNode* root) {
		if (root == 0) return;
		flatten(root->left);
		TreeNode *right = root->right;
		root->right = root->left;
		root->left = 0;
		while (root->right != 0) {
			root = root->right;
		}
		root->right = right;
		flatten(root->right);
	}
};
