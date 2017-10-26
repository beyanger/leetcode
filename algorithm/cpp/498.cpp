
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return {};

		int h = matrix.size(), w = matrix[0].size();
		int length = h * w;
		int y = 0, x = 0, dir = 0;
		vector<int> ans;
		while (ans.size() < length) {
			ans.push_back(matrix[y][x]);

			if (dir == 0) {
				if (x == w-1) {
					y++; dir = 1;
				} else if (y == 0) {
					x++; dir = 1;
				}  else {
					y--; x++;	
				}
			} else {
				if (y == h-1) {
					x++; dir = 0;
				} else if (x == 0) {
					y++; dir = 0;
				} else {
					y++; x--;
				}
			}
		}
		return ans;
	}
};

