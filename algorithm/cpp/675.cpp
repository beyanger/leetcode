
class Solution {
    vector<vector<int>> f;
    queue<array<int, 2>> q;
    int h, w;
    int step;

    bool bfs(int target) {
        bool visited[50][50] = {false};
        for (;!q.empty(); step++) {
            for (int qs = (int)q.size(); qs > 0; qs--) {
                int y = q.front()[0], x = q.front()[1]; q.pop();
                if (visited[y][x]) continue;
                visited[y][x] = true;
                if (f[y][x] == target) {
                    q = queue<array<int, 2>>();
                    q.push({y, x}); return true;
                } 
                if (x > 0 && !visited[y][x-1] && f[y][x-1])
                    q.push({y, x-1});
                if (x < w && !visited[y][x+1] && f[y][x+1])
                    q.push({y, x+1});
                if (y > 0 && !visited[y-1][x] && f[y-1][x])
                    q.push({y-1, x});
                if (y < h && !visited[y+1][x] && f[y+1][x])
                    q.push({y+1, x});
            }
        }
        return false;
    }

public:
    int cutOffTree(vector<vector<int>>& forest) {
        f = move(forest);
        h = (int)f.size()-1; w = (int)f[0].size()-1;
        vector<int> path;
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= w; j++) {
                if (f[i][j] <= 1) continue;
                path.push_back(f[i][j]);
            }
        }
        sort(path.begin(), path.end());
        q.push({0, 0});
        step = 0;
        for (int p : path)
            if (!bfs(p)) return -1;

        return step;
    }
};
