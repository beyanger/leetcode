
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (string& s : strs) {
            int cnt[2] = {};
            for (char c : s)  cnt[c-'0']++;
            for (int i = m, ii = m-cnt[0]; ii >= 0; i--, ii--) {
                for (int j = n, jj=n-cnt[1]; jj >= 0; j--, jj--) 
                    dp[i][j] = max(dp[i][j], dp[ii][jj]+1);
        }
        return dp[m][n];
    }
};
