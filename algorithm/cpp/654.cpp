
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
	TreeNode *buildTree(vector<int>::iterator begin, vector<int>::iterator end) {
		if (begin >= end) return 0;
		auto itr = max_element(begin, end);
		TreeNode *node = new TreeNode(*itr);
		node->left = buildTree(begin, itr);
		node->right = buildTree(itr+1, end);
		return node;
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return buildTree(nums.begin(), nums.end());
	}
};
