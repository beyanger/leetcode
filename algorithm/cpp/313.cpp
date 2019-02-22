

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int lp = (int)primes.size();
        int dp[n], dv[lp];
        dp[0] = 1;
        vector<int> index(lp);
        for (int i = 1; i < n; i++) {
            int v = INT_MAX;
            for (int j = 0; j < lp; j++) {
                v = min(v, dv[j] = dp[index[j]]*primes[j]);
            }
            dp[i] = v;
            for (int j = 0; j < lp; j++) {
                if (v == dv[j]) index[j]++;
            }
        }

        return dp[n-1];
    }
};
