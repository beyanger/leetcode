
class Solution {
    vector<vector<string>> ans;
    int col[16] = {}, right[32] = {}, left[32] = {};
    void dfs(vector<string>& cr, int n, int row) {
        if (row == n) { ans.push_back(cr); return; }
        for (int i = 0; i < n; i++) {
            if (col[i] || right[i+row] || left[i-row+n]) continue;
            col[i] = right[i+row] = left[i-row+n] = 1;
            cr[row][i] = 'Q';
            dfs(cr, n, row+1);
            cr[row][i] = '.';
            col[i] = right[i+row] = left[i-row+n] = 0;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cr(n, string(n, '.'));
        dfs(cr, n, 0);
        return ans;
    }
};

