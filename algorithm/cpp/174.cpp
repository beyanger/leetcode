
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int h = dungeon.size(), w = dungeon[0].size();
        vector<vector<int>> dp(h+1, vector<int>(w+1, INT_MAX));

        dp[h][w-1] = dp[h-1][w] = 1;
        for (int i = h-1; i >= 0; i--) {
            for (int j = w-1; j >= 0; j--) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};
