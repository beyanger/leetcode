
class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0, balance = 0;
        for (char c : S) {
            if (c == '(') balance++;
            else {
                balance--;
                if (balance < 0) {
                    ans++;
                    balance++;
                }
            }
        }
        return ans + balance;
    }
};
