
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    struct cmp {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (ListNode *l : lists) if (l) q.push(l);
        ListNode dummy(0), *cr = &dummy;
        while (!q.empty()) {
            cr = cr->next = q.top(); q.pop();
            if (cr->next) q.push(cr->next);
        }
        return dummy.next;
    }
};

