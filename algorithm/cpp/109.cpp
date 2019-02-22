
class Solution {
    TreeNode *buildTree(vector<int>& num, int i, int j) {
        if (i > j) return 0;
        int mid = (i+j)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildTree(num, i, mid-1);
        root->right = buildTree(num, mid+1, j);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> num;
        while (head) {
            num.push_back(head->val); head = head->next;
        }
        return buildTree(num, 0, num.size()-1);
    }
};


