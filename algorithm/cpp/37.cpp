
class Solution {
    int row[9][9] = {};
    int col[9][9] = {};
    int cel[9][9] = {};

    bool solve(vector<vector<char>>& board, int pos) {
        if (pos == 81) return true;
        int r = pos / 9, c = pos % 9;
        if (board[r][c] != '.') 
            return solve(board, pos+1); 
        
        int k = r/3*3 + c/3;
        for (int i = 0; i < 9; i++) {
            if (row[r][i] || col[c][i] || cel[k][i]) continue;
            row[r][i] = col[c][i] = cel[k][i] = 1;
            if (solve(board, pos+1)) {
                board[r][c] = i + '1';
                return true;
            }
            row[r][i] = col[c][i] = cel[k][i] = 0;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int k = r/3*3 + c/3;
                int i = board[r][c] - '1';
                row[r][i] = col[c][i] = cel[k][i] = 1;
            }
        }
        solve(board, 0);
    }
};

