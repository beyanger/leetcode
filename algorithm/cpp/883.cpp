
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int h = grid.size(), w = grid[0].size();
        vector<int> y(h), x(w);

        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 0) continue;
                y[i] = max(y[i], grid[i][j]);
                x[j] = max(x[j], grid[i][j]);
                ans++;
            }
        }

        return accumulate(y.begin(), y.end(), accumulate(x.begin(), x.end(), ans));
    }
};
