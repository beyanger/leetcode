
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int sa = s1.size(), sb = s2.size();
        if (sa+sb != s3.size()) return false;
        vector<vector<bool>> dp(sa+1, vector<bool>(sb+1));

        for (int i = 0; i <= sa; i++) {
            for (int j = 0; j <= sb; j++) {
                if (i == 0) {
                    if (j == 0) dp[i][j] = true;
                    else dp[i][j] = dp[i][j-1] && s2[j-1]==s3[j-1];
                } else {
                    if (j == 0) dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i-1];
                    else dp[i][j] = (s1[i-1]==s3[i+j-1] && dp[i-1][j])||(s2[j-1]==s3[i+j-1] && dp[i][j-1]);
                }
            }
        }
        return dp[sa][sb];
    }
};
