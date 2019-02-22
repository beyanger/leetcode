
class Solution {
    vector<vector<int>> height, m;
    int h, w;
    int dfs(int y, int x) {
        if (height[y][x]) return height[y][x];
        int cr = 0;
        if (x > 0 && m[y][x] < m[y][x-1]) cr = max(cr, dfs(y, x-1));
        if (x < w && m[y][x] < m[y][x+1]) cr = max(cr, dfs(y, x+1));
        if (y > 0 && m[y][x] < m[y-1][x]) cr = max(cr, dfs(y-1, x));
        if (y < h && m[y][x] < m[y+1][x]) cr = max(cr, dfs(y+1, x));
        return height[y][x] = cr + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        h = matrix.size()-1, w = matrix[0].size()-1;
        height = vector<vector<int>>(h+1, vector<int>(w+1));
        m = matrix;
        int ans = 0;
        for (int y = 0; y <= h; y++) {
            for (int x = 0; x <= w; x++) {
                ans = max(ans, dfs(y, x)); 
            }
        }
        return ans;
    }
};


