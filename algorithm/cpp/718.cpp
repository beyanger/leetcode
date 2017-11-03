
class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int sa = A.size(), sb = B.size();
		int ans = 0, dp[sb+1] = {0};

		for (int i = 0; i < sa; i++) {
			for (int j = sb-1; j >= 0; j--) {
				ans = max(ans, dp[j+1] = (A[i]==B[j] ? dp[j]+1 : 0));
			}
		}
		return ans;                                                        
	}
};


