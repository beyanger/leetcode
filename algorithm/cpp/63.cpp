class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size(), w = obstacleGrid[0].size();
        vector<vector<int>> dp(h, vector<int>(w));
        for (int i = 0; i < w && obstacleGrid[0][i] == 0; i++)
            dp[0][i] = 1;
        for (int i = 0; i < h && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;

        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[h-1][w-1];
    }
};
