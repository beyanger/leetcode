
class Solution {
public:
	int countBinarySubstrings(string s) {
		vector<int> dp(s.size());
		int t = 0;
		dp[t] = 1;
		for (int i = 1; i < s.size(); i++) 
			if (s[i] == s[i-1]) dp[t]++;
			else dp[++t] = 1;
		int res = 0;
		for (int i = 1; i <= t; i++)
			res += min(dp[i], dp[i-1]);
		return res;
	}
};


