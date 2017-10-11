
class Solution {
	int helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int h, int w, int y, int x) {
		if (grid[y][x]==0 || visited[y][x]==true) return 0;

		visited[y][x] = true;
		int area = 1;
		if (y > 0) area += helper(grid, visited, h, w, y-1, x);
		if (y < h-1) area += helper(grid, visited, h, w, y+1, x);
		if (x > 0) area += helper(grid, visited, h, w, y, x-1);
		if (x < w-1) area += helper(grid, visited, h, w, y, x+1);

		return area;
	}

public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {  
		if (grid.empty() || grid[0].empty()) return 0;
		
		int h = grid.size(), w = grid[0].size();
		vector<vector<bool>> visited(h, vector<bool>(w, false));

		int area = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				area = max(area, helper(grid, visited, h, w, y, x));
			}
		}
		return area;
	}
}

