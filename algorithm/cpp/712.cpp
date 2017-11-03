
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int la = s1.size(), lb = s2.size();
		int sa = accumulate(s1.begin(), s1.end(), 0);
		int sb = accumulate(s2.begin(), s2.end(), 0);

		vector<vector<int>> dp(la+1, vector<int>(lb+1));
		for (int i = 0; i < la; i++) {
			for (int j = 0; j < lb; j++) {
				dp[i+1][j+1] = (s1[i] == s2[j]) ? dp[i][j]+s1[i] : max(dp[i+1][j], dp[i][j+1]);
			}
		}
		return sa + sb - 2*dp[la][lb];
	}
};



