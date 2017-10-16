
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

	int maxPathSum(TreeNode *root, int& max_sum) {
		if (root == NULL) return 0;
		int l = maxPathSum(root->left, max_sum);
		int r = maxPathSum(root->right, max_sum);
		int rs = root->val;
		if (l > 0) rs += l;
		if (r > 0) rs += r;
		max_sum = max(max_sum, rs);
		int m = max(l, r);
		if (m > 0) return m + root->val;
		return root->val;
	}
public:
	int maxPathSum(TreeNode* root) {
		int max_sum = INT_MIN;
		maxPathSum(root, max_sum);
		return max_sum;
	}
};



