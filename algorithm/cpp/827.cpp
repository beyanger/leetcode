class Solution {
    vector<vector<int>> g;
    int h, w;

    int dfs(int y, int x, int v) {
        int res = 1;
        g[y][x] = v;
        if (y > 0 && g[y-1][x] == 1)
            res += dfs(y-1, x, v);

        if (y < h && g[y+1][x] == 1)
            res += dfs(y+1, x, v);

        if (x > 0 && g[y][x-1] == 1)
            res += dfs(y, x-1, v);

        if (x < w && g[y][x+1] == 1)
            res += dfs(y, x+1, v);
        return res;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int s[2500] = {0};
        h = grid.size() - 1;
        w = grid[0].size() - 1;
        int v = 2;
        int ans = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    s[v] = dfs(i, j, v);    
                    ans = max(s[v++], ans);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 0) {
                    int csum = 0, t;
                    int visited[2500] = {0};
                    if (i > 0) {
                        t = grid[i-1][j];
                        if (t != 0 && visited[t] == 0) {
                            csum += s[t];
                            visited[t] = 1;
                        }
                    } 

                    if (i < h-1) {
                        t = grid[i+1][j];
                        if (t != 0 && visited[t] == 0) {
                            csum += s[t];
                            visited[t] = 1;
                        }
                    }

                    if (j > 0) {
                        t = grid[i][j-1];
                        if (t != 0 && visited[t] == 0) {
                            csum += s[t];
                            visited[t] = 1;
                        }
                    }

                    if (j < w-1) {
                        t = grid[i][j+1];
                        if (t != 0 && visited[t] == 0) {
                            csum += s[t];
                            visited[t] = 1;
                        }
                    }
                    ans = max(csum, ans);
                }
            }
        }
                        
        return min(ans + 1, h*w);
    }
};

