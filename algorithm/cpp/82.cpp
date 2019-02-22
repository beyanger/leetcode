
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* root = head->next;
        while (root && root->val == head->val) {
            root = root->next;
        }
        if (root != head->next) return deleteDuplicates(root);
        head->next = deleteDuplicates(root);
        return head;
    }
};

