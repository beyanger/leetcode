
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    Node *prev = NULL;

    void dfs(Node *head) {
        if (!head) return;
        head->prev = prev;
        if (prev) prev->next = head;
        prev = head;
        Node *next = head->next;
        dfs(head->child);
        head->child = NULL;
        dfs(next);
    }
public:

    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};

