
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> y(grid.size());
        vector<int> x(grid[0].size());

        int sum = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    sum++;
                    if (y[i] < grid[i][j]) y[i] = grid[i][j];
                    if (x[j] < grid[i][j]) x[j] = grid[i][j];
                }
            }
        }

        sum = accumulate(y.begin(), y.end(), sum);
        return  accumulate(x.begin(), x.end(), sum);
    }
};
