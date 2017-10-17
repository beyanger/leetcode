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
	int minDepth(TreeNode* root) {
		if (root == 0) return 0;
		if (root->left == 0) return minDepth(root->right) + 1;
		if (root->right == 0) return minDepth(root->left) + 1;
		return min(minDepth(root->right), minDepth(root->left)) + 1;
	}
};

