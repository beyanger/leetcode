
class Solution {
    unordered_map<int, vector<int>> xline, yline;

    int dfs(vector<vector<int>>& st, vector<bool>& visited, int cr) {
        visited[cr] = true;
        int ans = 1;
        for (int n : xline[st[cr][0]]) 
            if (!visited[n]) 
                ans += dfs(st, visited, n);
        for (int n : yline[st[cr][1]]) 
            if (!visited[n]) 
                ans += dfs(st, visited, n);
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int ls = stones.size();
        vector<bool> visited(ls);
        for (int i = 0; i < ls; i++) {
            xline[stones[i][0]].push_back(i);
            yline[stones[i][1]].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < ls; i++) {
            if (visited[i]) continue;
            ans += dfs(stones, visited, i) - 1;
        }
        return ans;
    }
};
