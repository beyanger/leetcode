
class Solution {
public:
    int nthUglyNumber(int n) {
        int  dp[1690];
        int i2 = 0, i3 = 0, i5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int v2 = dp[i2]*2, v3 = dp[i3]*3, v5 = dp[i5]*5;
            int v = dp[i] = min(v2, min(v3, v5));
            if (v == v2) i2++;
            if (v == v3) i3++;
            if (v == v5) i5++;
        }
        return dp[n-1];
    }
};
