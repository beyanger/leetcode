
class Solution {
	void dfs(int i, int n, vector<bool>& v, vector<bool>& a, vector<bool>& b, int& cnt) {
		if (i == n) {
			cnt++;
			return;
		}
		for (int j = 0; j < n; j++) {
			int b1 = i + j, b2 = i-j+n-1;
			if (!v[j] && !a[b1] && !b[b2]) {
				v[j] = a[b1] = b[b2] = true;
				dfs(i+1, n, v, a, b, cnt);
				v[j] = a[b1] = b[b2] = false;
			}                                                                 
		}
	}

public:
	int totalNQueens(int n) {
		int ans = 0;
		vector<bool> v(n), a(2*n), b(2*n);
		dfs(0, n, v, a, b, ans);
		return ans;
	}
};

