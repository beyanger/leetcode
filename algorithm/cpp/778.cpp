class Solution {
    struct Point {
        int t, y, x;
        friend bool operator<(const Point& a, const Point& b) {
            return a.t > b.t;
        }
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        int lg = grid.size();
        vector<vector<int>> ex(lg, vector<int>(lg));
        priority_queue<Point> q;
        q.push({grid[0][0], 0, 0});

        int ans = grid[0][0];
        while (!q.empty()) {
            Point top = q.top(); q.pop();
            int x = top.x, y = top.y;
            if (ex[y][x]) continue;
            ans = max(ans, top.t);
            if (x == y && x == lg-1) return ans;
            ex[y][x] = 1;
            if (y > 0 && ex[y-1][x] == 0) q.push({grid[y-1][x], y-1, x});
            if (y < lg-1 && ex[y+1][x] == 0) q.push({grid[y+1][x], y+1, x});
            if (x > 0 && ex[y][x-1] == 0) q.push({grid[y][x-1], y, x-1});
            if (x < lg-1 && ex[y][x+1] == 0) q.push({grid[y][x+1], y, x+1});
        }
        return -1;
    }
};

