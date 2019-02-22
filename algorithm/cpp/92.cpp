
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0), *cr = &dummy, *orig, *next;
        dummy.next = head;
        for (m--; m > 0; m--, n--)
            cr = cr->next;
        head = cr;
        orig = cr = cr->next;
        while (n--) {
            next = cr->next;
            cr->next = head->next;
            head->next = cr;
            cr = next;
        }
        orig->next = cr;
        return dummy.next;
    }
};
