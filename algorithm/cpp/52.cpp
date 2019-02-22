
class Solution {
    int col[16] = {}, right[32] = {}, left[32] = {};
    int ans = 0;
    void dfs(int n, int row) {
        if (row == n) { ans++; return; }
        for (int i = 0; i < n; i++) {
            if (col[i] || right[i+row] || left[i-row+n]) continue;
            col[i] = right[i+row] = left[i-row+n] = 1;
            dfs(n, row+1);
            col[i] = right[i+row] = left[i-row+n] = 0;
        }
    }

public:
    int totalNQueens(int n) {
        dfs(n, 0);
        return ans;
    }
};
