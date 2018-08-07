
class Solution {
    union point {
        struct { int32_t x, y; };
        int64_t key;
        int ed() { return x*x + y*y; } // square of Euclidean distance
    };
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        static const int turn[][4] = {{0}, {1, 2, 3, 0}, {3, 0, 1, 2}};
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        unordered_set<int64_t> hs;
        point pt, cr = {{ .x = 0, .y = 0}};
        int direction = 0;
        int ans = cr.ed();
        for (vector<int>& o : obstacles) {
            pt.x = o[0], pt.y = o[1]; 
            hs.insert(pt.key);
        }

        for (int c : commands) {
            if (c < 0) {
                direction = turn[-c][direction]; 
            } else {
                for (int i = 1; i <= c; i++) {
                    pt.x = cr.x + dx[direction];
                    pt.y = cr.y + dy[direction];
                    if (hs.count(pt.key) != 0) { // obstacle
                        break;
                    }
                    cr = pt; 
                } 
                ans = max(ans, cr.ed()); 
            }
        }

        return ans;
    }
};

