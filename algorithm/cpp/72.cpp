
class Solution {
public:
    int minDistance(string word1, string word2) {

        int s1 = word1.size(), s2 = word2.size();
        if (s1 == 0) return s2;
        if (s2 == 0) return s1;

        vector<vector<int>> dp(s1+1, vector<int>(s2+1));

        for (int i = 1; i <= s1; i++) dp[i][0] = i;
        for (int j = 1; j <= s2; j++) dp[0][j] = j;

        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;
                }
            }
        }

        return dp[s1][s2];
    }
};
