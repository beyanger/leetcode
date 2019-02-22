
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
	ListNode *add(ListNode *l1, ListNode *l2, int carry) {
		if (!l1 && !l2 && !carry) return nullptr;
		if (l1) { carry += l1->val; l1 = l1->next;}
		if (l2) { carry += l2->val; l2 = l2->next;}
		ListNode *node = new ListNode(carry % 10);
		node->next = helper(l1, l2, carry/10);
		return node;
	}
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode* l2) {
		return add(l1, l2, 0);
	}
};

