
class Solution {
public:
    bool isNumber(string s) {
        vector<vector<int>> dp(9, vector<int>(128, -1));
        for (int i = '0'; i <= '9'; i++) {
            dp[0][i] = dp[1][i] = dp[2][i] = 2;
            dp[3][i] = dp[4][i] = 4;
            dp[5][i] = dp[6][i] = dp[7][i] = 6;
        }
        dp[0][' '] = 0;
        dp[0]['+'] = dp[0]['-'] = 1;
        dp[0]['.'] = dp[1]['.'] = 3;
        dp[2]['.'] = 4;
        dp[2]['e'] = dp[4]['e'] = 5;
        dp[5]['+'] = dp[5]['-'] = 7;
        dp[2][' '] = dp[4][' '] = dp[6][' '] = dp[8][' '] = 8;

        int stat = 0;
        for (char c : s) {
            stat = dp[stat][c];
            if (stat < 0) return false;
        }
        return stat==2 || stat==4 || stat==6 || stat==8;
    }
};

