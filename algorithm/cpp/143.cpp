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
    void reorderList(ListNode* head) {
        if (!head) return;
        vector<ListNode *> p;
        while (head) {
            p.push_back(head);
            head = head->next;
        }
        int i = 0, j = (int)p.size()-1;
        for (; i < j; i++, j--) {
            p[i]->next = p[j];
            p[j]->next = p[i+1];
        }
        p[i]->next = 0;
    }
};
