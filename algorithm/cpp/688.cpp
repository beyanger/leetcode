
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N));
        dp[r][c] = 1.0;
        for (int i = 0; i < K; i++) {
            vector<vector<double>> dq(N, vector<double>(N));
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (dp[y][x] == 0.0) continue;
                    double v = dp[y][x] * 0.125;
                    if (y > 1) {
                        if (x > 0) dq[y-2][x-1] += v;
                        if (x < N-1) dq[y-2][x+1] += v;
                    }
                    if (y < N-2) {
                        if (x > 0) dq[y+2][x-1] += v;
                        if (x < N-1) dq[y+2][x+1] += v;
                    }
                    if (x > 1) {
                        if (y > 0) dq[y-1][x-2] += v;
                        if (y < N-1) dq[y+1][x-2] += v;
                    }
                    if (x < N-2) {
                        if (y > 0) dq[y-1][x+2] += v;
                        if (y < N-1) dq[y+1][x+2] += v;
                    }
                }
            }
            dp = dq;
        }
        double res = 0.0;
        for (auto d : dp) res = accumulate(d.begin(), d.end(), res);
        return res;
    }
};

