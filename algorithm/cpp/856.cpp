
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> cr;
        cr.push(0);
        for (char c : S) {
            if (c == '(') cr.push(0);
            else {
                int v = cr.top(); cr.pop();
                cr.top() += max(1, v*2);
            }
        }
        return cr.top();
    }
};
