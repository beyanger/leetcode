
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int tar = stoi(target);
        if (tar == 0) return 0;
        int visited[10000] = {};
        for (string &d : deadends) 
            visited[stoi(d)] = 1;
        const int delta[] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        int step = 1;
        queue<int> q;
        for (q.push(0); !q.empty(); step++) {
            for (int qs = (int)q.size(); qs > 0; qs--) {
                int cr = q.front(); q.pop();
                if (visited[cr]) continue;
                visited[cr] = 1;
                for (int i = 1; i < 10000; i *= 10) {
                    int g = cr / i % 10;
                    int orig = cr - g * i;
                    int t1 = orig + delta[g+2]*i;
                    if (t1 == tar) return step;
                    q.push(t1);

                    int t2 = orig + delta[g]*i;
                    if (t2 == tar) return step;
                    q.push(t2);
                }
            }
        }
        return -1;
    }
};
