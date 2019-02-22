
struct DSU {
    vector<int> f;
    vector<int> n;

    DSU(int s) : f(s), n(s, 1) {
        for (int i = 0; i < s; i++) f[i] = i; 
    }

    int find(int i) {
        if (f[i] == f[f[i]]) return f[i];
        return f[i] = find(f[i]);
    }

    void merge(int i, int j) {
        int fi = find(i), fj = find(j);
        if (fi == fj) return;
        f[fi] = fj;
        n[fj] += n[fi];
    }
};


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        static const int delta[] = {-1, 0, 1, 0, -1};
        int h = grid.size(), w = grid[0].size();
        
        for (auto& ht : hits) 
            if (grid[ht[0]][ht[1]] == 1) 
                grid[ht[0]][ht[1]] = 2;

        DSU dsu(h*w + 1);
        int end = h*w, k = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++, k++) {
                if (grid[i][j] != 1) continue;
                if (i == 0) dsu.merge(k, end);
                if (i > 0 && grid[i-1][j] == 1) dsu.merge(k, k-w);
                if (j > 0 && grid[i][j-1] == 1) dsu.merge(k, k-1);
            }
        }

        int count = dsu.n[dsu.find(end)];
        int lt = hits.size();
        vector<int> ans(lt);
        for (int i = lt-1; i >= 0; i--) {
            int y = hits[i][0], x = hits[i][1];
            if (grid[y][x] == 2) {
                int idx = y*w + x;
                if (y > 0 && grid[y-1][x]==1) dsu.merge(idx, (y-1)*w+x);
                if (y < h-1 && grid[y+1][x]==1) dsu.merge(idx, (y+1)*w+x);
                if (x > 0 && grid[y][x-1]==1) dsu.merge(idx, y*w+x-1);
                if (x < w-1 && grid[y][x+1]==1) dsu.merge(idx, y*w+x+1);
                if (y == 0) dsu.merge(y*w+x, end);
                grid[y][x] = 1;
            } 
            int ns = dsu.n[dsu.find(end)];
            ans[i] = (ns > count) ? ns-count-1 : 0;
            count = ns;
        }
        return ans;
    }
};

