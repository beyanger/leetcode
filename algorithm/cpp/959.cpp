

struct DSU {
    vector<int> p;

    DSU(int n) : p(n) {
        for (int i = 0; i < n; i++) 
            p[i] = i;
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        p[find(x)] = find(y);
    }
    int count() const {
        int i = 0, cnt = 0;
        for (int v : p) {
            if (v == i++) cnt++;
        }
        return cnt;
    }
};


class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(4*n*n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = 4 * (i * n + j);

                if (grid[i][j] == ' ') {
                    dsu.merge(idx, idx+1);
                    dsu.merge(idx, idx+2);
                    dsu.merge(idx, idx+3);
                } else if (grid[i][j] == '/') {
                    dsu.merge(idx, idx+3);
                    dsu.merge(idx+1, idx+2);
                } else {
                    dsu.merge(idx, idx+1);
                    dsu.merge(idx+2, idx+3);
                }

                if (i > 0) 
                    dsu.merge(idx, idx-4*n+2);
                if (j > 0) 
                    dsu.merge(idx+3, idx-3);

            }
        }
        return dsu.count();

    }
};

