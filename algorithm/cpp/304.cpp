
class NumMatrix {
	vector<vector<int>> m;
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty() || matrix[0].empty()) return;
		int h = matrix.size(), w = matrix[0].size();
		m = vector<vector<int>>(h+1, vector<int>(w+1));
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				m[y+1][x+1] = m[y+1][x] + m[y][x+1] + matrix[y][x] - m[y][x];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return m[row2+1][col2+1]+m[row1][col1] - m[row2+1][col1]-m[row1][col2+1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
