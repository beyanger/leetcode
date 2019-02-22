
struct DSU {
    int n;
    vector<int> f;

    DSU(int n) : n(n), f(n) {
        for (int i = 0; i < n; i++) f[i] = i;
    }

    int find(int i) {
        if (f[i] == f[f[i]]) return f[i];
        return f[i] = find(f[i]);
    }

    void merge(int i, int j) {
        int fi = find(i), fj = find(j);
        if (fi == fj) return;
        f[fj] = fi; n--;
    }

    bool isconnected(int i, int j) {
        return find(i) == find(j);
    }
};


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            dsu.merge(row[i*2]/2, row[i*2+1]/2);
        }
        return n- dsu.n;
    }
};
