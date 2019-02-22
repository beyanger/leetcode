class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int visited[30][30][64] = {};
        int h = (int)grid.size(), w = (int)grid[0].size();
        queue<array<int, 3>> q;
        int keys = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c = grid[i][j];
                if ('a' <= c && c <= 'f') {
                    keys |= (1 << (c-'a'));
                } else if (c == '@') {
                    q.push({i, j, 0});
                } 
            }
        }
        int delta[] = {-1, 0, 1, 0, -1};
        int step = 1;
        while (!q.empty()) {
            for (int qs = (int)q.size(); qs > 0; qs--) {
                array<int, 3> cr = q.front(); q.pop();
                int y = cr[0], x = cr[1], k = cr[2];
                if (visited[y][x][k]) continue;
                visited[y][x][k] = 1;
                for (int i = 0; i < 4; i++) {
                    int nk = k;
                    int nx = x + delta[i];
                    int ny = y + delta[i+1];
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                    char c = grid[ny][nx];
                    if (c == '#') continue;
                    if ('A' <= c && c <= 'F' && !(k & (1<<(c-'A')))) continue;
                    if ('a' <= c && c <= 'f') nk |= 1 << (c-'a');
                    if (visited[ny][nx][nk]) continue;
                    if (nk == keys) return step;
                    q.push({ny, nx, nk});
                }
            }
            step++;
        }
        return -1;
    }
};
