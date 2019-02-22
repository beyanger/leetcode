class Solution {
public:
    int distinctSubseqII(string S) {
        const int mod = 1e9 + 7;
        long dp = 1, mark[26] = {};
        for (char c : S) {
            int diff = c - 'a';
            long prev = mark[diff];
            mark[diff] = dp;
            dp = (dp * 2 - prev + mod) % mod;
        }
        return dp - 1;
    }
};
