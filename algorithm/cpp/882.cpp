
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<array<int, 2>>> dp(N);
        for (vector<int>& e : edges) {
            dp[e[0]].push_back({e[1], e[2]});
            dp[e[1]].push_back({e[0], e[2]});
        }
        vector<int> radius(N, -1);
        queue<array<int, 2>> q;
        for (q.push({0, M}); !q.empty(); q.pop()) {
            int i = q.front()[0], r = q.front()[1];
            if (r <= radius[i]) continue;
            radius[i] = r;
            for (array<int, 2>& next : dp[i]) {
                int ni = next[0];
                int nr = r - next[1] - 1;
                if (nr > radius[ni]) q.push({ni, nr});
            }
        }
        int ans = 0;
        for (int r : radius) 
            if (r >= 0) ans++;
        for (vector<int>& e : edges) {
            ans += min(max(radius[e[0]], 0)+max(radius[e[1]], 0) , e[2]);
        }
        return ans;
    }
};

