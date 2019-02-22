
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int sa = s1.size(), sb = s2.size();
        if (sa+sb != s3.size()) return false;

        vector<vector<bool>> dp(sa+1, vector<bool>(sb+1));
        dp[0][0] = true;
        for (int i = 0; i < sa && s1[i]==s3[i]; i++) 
            dp[i+1][0] = true;
        for (int i = 0; i < sb && s2[i]==s3[i]; i++)
            dp[0][i+1] = true;

        for (int i = 1; i <= sa; i++) {
            for (int j = 1; j <= sb; j++) {
                dp[i][j] = ((dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[sa][sb];
    }
};

