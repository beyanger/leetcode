class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int h = board.size(), w = board[0].size();
        int end = h*w, dj = 1;
        vector<bool> visited(end+1);
        vector<array<int, 2>> pos(1);
        for (int i = h-1, j = -1; i >= 0; i--, dj=-dj)
            for (j+=dj; 0 <= j && j < w; j+=dj)
                pos.push_back({i, j});
        queue<int> q;
        int step = 1;
        for (q.push(1); !q.empty(); step++) {
            for (int qs = q.size(); qs > 0; qs--) {
                int p = q.front(); q.pop();
                visited[p] = true;
                int e = min(p+6, end);
                if (e == end) return step;
                for (; e > p; e--) {
                    int b = board[pos[e][0]][pos[e][1]];
                    if (b == -1) {
                        if (!visited[e]) q.push(e);
                    } else {
                        if (b == end) return step;
                        if (!visited[b]) q.push(b);
                    }
                }
            }
        }
        return -1;
    }
};

