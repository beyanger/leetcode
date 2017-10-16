
class Solution {

    int sum(vector<int>& dp, int start, int end) {
        const int MOD = 1e9 + 7;
        int res = 0;
        for (int i = start; i <= end; i++) 
            res = (res + dp[i]) % MOD;
        return res;
    }
public:
    int checkRecord(int n) {
        vector<int> dp = {1, 1, 0, 1, 0, 0};
        for (int i = 1; i < n; i++) {
            dp = {sum(dp, 0, 2), dp[0], dp[1], sum(dp, 0, 5), dp[3], dp[4]};
        }
        return sum(dp, 0, 5);
    }
};

