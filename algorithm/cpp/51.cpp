
class Solution {
	void dfs(int i, int n, vector<bool>& v, vector<bool>& a, vector<bool>& b, vector<string>& x, vector<vector<string>>& ans) {
		if (i == n) {
			ans.push_back(x);
			return;
		}
		for (int j = 0; j < n; j++) {
			int b1 = i + j, b2 = i-j+n-1;
			if (v[j] == false && a[b1] == false && b[b2] == false) {
				v[j] = a[b1] = b[b2] = true;
				x[i][j] = 'Q';
				dfs(i+1, n, v, a, b, x, ans);
				x[i][j] = '.';
				v[j] = a[b1] = b[b2] = false;
			}                                                                 
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> x(n, string(n, '.'));
		vector<vector<string>> ans;
		vector<bool> v(n), a(2*n), b(2*n);
		dfs(0, n, v, a, b, x, ans);
		return ans;
	}
};

