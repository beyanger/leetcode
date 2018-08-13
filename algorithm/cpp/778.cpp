class Solution {
public:
    struct point {
        int t, y, x;
        friend bool operator<(const point& p1, const point& p2) {
            return p1.t > p2.t;
        }
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<point> q;
        int ts = grid.front().front();
        q.push({ts, 0, 0});

        int h = grid.size()-1, w = grid[0].size()-1;
        vector<vector<bool>> visited(h+1, vector<bool>(w+1, false));

        while (!q.empty()) {
            point top = q.top();
            q.pop();
            int y = top.y, x = top.x, t = top.t;
            visited[y][x] = true;
            if (y > 0 && !visited[y-1][x]) 
                q.push({grid[y-1][x], y-1, x});
            if (y < h && !visited[y+1][x]) 
                q.push({grid[y+1][x], y+1, x});
            if (x > 0 && !visited[y][x-1]) 
                q.push({grid[y][x-1], y, x-1});
            if (x < w && !visited[y][x+1]) 
                q.push({grid[y][x+1], y, x+1});

            ts = max(ts, t);

            if (visited.back().back()) 
                return ts;
        }

        return -1;
    }
};

