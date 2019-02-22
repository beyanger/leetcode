
struct DSU {
    int n;
    int f[8192];
    DSU(int n) : n(n) {
        for (int i = 0; i < n; i++) 
            f[i] = i; 
    }
    int find(int i) {
        if (f[i] == f[f[i]]) return f[i];
        return f[i] = find(f[i]);
    }
    bool isconnected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return;
        f[i] = j; n--;
    }
};

class Solution {

    bool compare(array<int, 26>& a, array<int, 26>& b) {
        return memcmp(a.data(), b.data(), 26*sizeof(int)) == 0;
    }
    
    int check(string& a, string& b) {
        int ld = a.size(), ans = 0;
        for (int i = 0; i < ld; i++) {
            if (a[i] != b[i] && ans++==2) {
                    return 3;
            }
        }
        return ans;
    }

public:
    int numSimilarGroups(vector<string>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int la = A.size(), ld = A[0].size();
        DSU dsu(la);
        vector<array<int, 26>> freq;
        vector<bool> hassame;
        for (string& a : A) {
            array<int, 26> cr = {};
            for (char c : a) cr[c-'a']++; 
            bool same = false;
            for (int c : cr) if (c > 1) { same = true; break;}
            freq.push_back(cr);
            hassame.push_back(same);
        }

        for (int i = 0; i < la; i++) {
            for (int j = 0; j < i; j++) {
                if (dsu.isconnected(i, j)) continue;
                if (!compare(freq[i], freq[j])) continue;
                int r = check(A[i], A[j]);
                if (r == 2 || (r == 0 && hassame[i])) {
                    dsu.merge(i, j);
                }
            }
        }
        return dsu.n;
    }
};


