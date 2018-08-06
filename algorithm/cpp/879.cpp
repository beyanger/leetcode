
class Solution {
public:
int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp(P+1, vector<int>(G+1, 0));

    for (size_t i = 0; i < group.size(); i++) {
        int g = group[i], p = profit[i];
        if (g > G) continue;

        int gend = G - g;
        auto bp = dp;
        for (int m = 0; m <= P; m++) {
            int pend = m + p;
            if (pend > P) pend = P;
            for (int n = 1; n <= gend; n++) {
                if (dp[m][n]) {
                    bp[pend][n+g] = (bp[pend][n+g] + dp[m][n]) % MOD;
                }
            }
        }
        if (p > P) p = P;
        bp[p][g]++;
        dp = bp;
    }

    return accumulate(dp.back().begin(), dp.back().end(), 0ULL) % MOD;
}
};

