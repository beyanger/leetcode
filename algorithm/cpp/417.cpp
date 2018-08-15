class Solution {
public:
    void dfs(vector<vector<int>>& m, vector<vector<bool>>& v, int h, int w, int y, int x) {
        v[y][x] = true;
        int hm = m[y][x];
        if (y > 0 && !v[y-1][x] && m[y-1][x] >= hm) 
            dfs(m, v, h, w, y-1, x);
        if (y < h && !v[y+1][x] && m[y+1][x] >= hm)
            dfs(m, v, h, w, y+1, x);
        if (x > 0 && !v[y][x-1] && m[y][x-1] >= hm)
            dfs(m, v, h, w, y, x-1);
        if (x < w && !v[y][x+1] && m[y][x+1] >= hm)
            dfs(m, v, h, w, y, x+1);
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) return {};
        int h = matrix.size()-1, w = matrix[0].size()-1;
        vector<pair<int, int>> ans;
        vector<vector<bool>> v1(h+1, vector<bool>(w+1)), v2 = v1;

        for (int i = 0; i <= w; i++) {
            dfs(matrix, v1, h, w, 0, i);
            dfs(matrix, v2, h, w, h, i);
        }
        for (int i = 0; i <= h; i++) {
            if (i != 0) dfs(matrix, v1, h, w, i, 0);
            if (i != h) dfs(matrix, v2, h, w, i, h);
        }
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= w; j++) {
                if (v1[i][j] && v2[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};

