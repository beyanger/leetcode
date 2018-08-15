
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> step(N, -1);
        vector<vector<short>> dp(N, vector<short>(N, -1));
        unordered_set<int> p1, p2;
        unordered_set<int> *q1 = &p1, *q2 = &p2;

        for (auto& e : edges) {
            int x = e[0], y = e[1];
            dp[x][y] = dp[y][x] = e[2];
        }

        p1.insert(0);
        step[0] = M;
        while (!q1->empty()) {
            for (auto itr = q1->begin(); itr != q1->end(); itr++) {
                int cr = *itr;
                for (int i = 0; i < N; i++) {
                    int r = dp[cr][i];
                    if (r >= 0) {
                        int ns = step[cr] - r - 1;
                        if (ns > step[i]) {
                            step[i] = ns;
                            q2->insert(i);
                        }
                    }
                }
            }
            q1->clear();
            swap(q1, q2);
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (step[i] >= 0)
                ans++;
            for (int j = i+1; j < N; j++) {
                int r = dp[i][j];
                if (r > 0) {
                    int si = max(step[i], 0);
                    int sj = max(step[j], 0);
                    ans += min(si+sj, r);
                }
            }
        }
        return ans;
    }
};

