
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int lg = graph.size();
        if (lg <= 1) return 0;
        queue<array<int, 2>> q;
        int visited[12][1<<12] = {};
        for (int i = 0; i < lg; i++) {
            if (graph[i].size() == 1)
                q.push({i, 1<<i});
        }
        if (q.empty()) q.push({0, 1});
        int key = (1<<lg)-1;
        
        for (int step = 1; !q.empty(); step++) {
            for (int qs = q.size(); qs > 0; qs--) {
                array<int, 2> cr = q.front(); q.pop();
                int p = cr[0], k = cr[1];
                if (visited[p][k]) continue;
                visited[p][k] = 1;
                for (int np : graph[p]) {
                    int nk = k | (1 << np);
                    if (visited[np][nk]) continue;
                    if (nk == key) return step;
                    q.push({np, nk});
                }
            }
        }
        return -1;
    }
};

