
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const static int delta[] = {0, 1, 0, -1, 0};
        const static int next[] = {1, 2, 3, 0};

        vector<vector<int>> res(n, vector<int>(n));
        int cv = 0, end = n * n;
        int y = 0, x = 0, dir = 0;

        while (++cv <= end) {
            res[y][x] = cv;
            int ny = y + delta[dir];
            int nx = x + delta[dir+1];
            if (ny==-1 || ny==n || nx==-1 || nx==n || res[ny][nx]!=0)
                dir = next[dir];
            y += delta[dir];
            x += delta[dir+1];
        }
        return res;
    }
};
