
class Heap {
    vector<array<int, 2>> val;
    vector<int> idx;
    int sz;

    void adjust_up(int i) {
        while (i > 0) {
            int p = (i-1)/2;
            if (val[i][0] <= val[p][0]) 
                return;
            swap(i, p);
            i = p;
        }
    }

    void adjust_down(int i) {
        while (true) {
            int c1 = i*2 + 1;
            if (c1 >= sz) return;
            int c2 = c1+1;
            int c = (c2 < sz && val[c2][0] > val[c1][0]) ? c2 : c1;
            if (val[c][0] <= val[i][0]) 
                return;
            swap(i, c);
            i = c;
        }
    }
    void swap(int i, int j) {
        if (i == j) return;
        std::swap(idx[val[i][1]], idx[val[j][1]]);
        std::swap(val[i], val[j]);
    }
    bool empty() const { return sz == 0; }
public:
    Heap(int size) : val(size), idx(size), sz(0) { }
    void add(int h, int id) {
        val[sz] = array<int, 2>{h, id};
        idx[id] = sz++;
        adjust_up(idx[id]);
    }
    void remove(int id) {
        int pidx = idx[id];
        swap(pidx, --sz);
        adjust_down(pidx);
    }
    int max() {
        if (empty()) return 0;
        return val[0][0];
    }

};


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<array<int, 3>> sl;
        int lb = (int)buildings.size();
        for (int i = 0; i < lb; i++) {
            sl.push_back({buildings[i][0], buildings[i][2], i});
            sl.push_back({buildings[i][1], -buildings[i][2], i});
        }
        sort(sl.begin(), sl.end(), [](array<int, 3>& a, array<int, 3>& b) {
                if (a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
                });
        Heap hp(lb);
        vector<pair<int, int>> ans;
        for (array<int, 3>& b : sl) {
            int x = b[0];
            int h = abs(b[1]);
            if (b[1] > 0) {
                if (h > hp.max()) 
                    ans.push_back({x, h});
                hp.add(h, b[2]);
            } else {
                hp.remove(b[2]);
                if (h > hp.max()) 
                    ans.push_back({x, hp.max()});
            }
            
        }
        return ans;
    }
};


