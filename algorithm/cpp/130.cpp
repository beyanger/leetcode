
class Solution {
	
	void helper(vector<vector<char>>& board, vector<vector<bool>>& visited, int h, int w, int y, int x) {
		if (board[y][x] == 'X' || visited[y][x] == true) return;

		visited[y][x] = true;
		if (0 < x)		helper(board, visited, h, w, y, x-1);
		if (x < w-1)	helper(board, visited, h, w, y, x+1);
		if (0 < y)		helper(board, visited, h, w, y-1, x);
		if (y < h-1)	helper(board, visited, h, w, y+1, x);
	}

public:
	void solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty()) return;

		int h = board.size(), w = board[0].size();

		vector<vector<bool>> visited(h, vector<bool>(w));

		for (int x = 0; x < w; x++) {
			helper(board, visited, h, w, 0, x);
			helper(board, visited, h, w, h-1, x);
		}

		for (int y = 0; y < h; y++) {
			helper(board, visited, h, w, y, 0);
			helper(board, visited, h, w, y, w-1);
		}

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (!visited[y][x]) board[y][x] = 'X';
			}
		}
	}
};

