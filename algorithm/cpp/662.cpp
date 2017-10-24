

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	int val;
 *  TreeNode *left;
 *  TreeNode *right;
 *	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		vector<pair<TreeNode *, int>> w;
		w.push_back(make_pair(root, 0));

		int ans = 0;
		while (!w.empty()) {
			vector<pair<TreeNode *, int>> t;

			ans = max(ans, w.back().second-w.front().second);

			for (auto& pr : w) {
				if (pr.first->left) t.push_back(make_pair(pr.first->left, pr.second*2));
				if (pr.first->right) t.push_back(make_pair(pr.first->right, pr.second*2+1));                            
			}
			w = t;
		}

		return ans + 1;                                        
	}
};

