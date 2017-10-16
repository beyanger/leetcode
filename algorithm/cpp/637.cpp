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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        vector<TreeNode *> le;
        le.push_back(root);
        while (le.size() > 0) {
			long sum = 0;
            vector<TreeNode *> ne;
            for (auto node : le) {
				sum += node->val;
                if (node->left) ne.push_back(node->left);
                if (node->right) ne.push_back(node->right);
            }
			res.push_back((double)sum / le.size());
            le = ne;
        }

        return res;
    }
};

