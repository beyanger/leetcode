
class Solution {
public:
    bool checkValidString(string s) {
        int min_op = 0, max_op = 0;
        for (char c : s) {
            if (c == '(') min_op++; else min_op--;
            if (c != ')') max_op++; else max_op--;
            if (max_op < 0) return false;
            if (min_op < 0) min_op = 0;
        }
        return min_op == 0;
    }
};
