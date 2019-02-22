
class Solution {
    int dfs(vector<vector<int>>& g, vector<int>& color, int cr, int cc) {
        color[cr] = cc;
        vector<int>& neigh = g[cr];

        int ln = neigh.size();
        int area = 1;
        for (int i = 0; i < ln; i++) {
            if (neigh[i] && color[i] == -1) {
                area += dfs(g, color, i, cc);
            }
        }
        return area;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int lg = graph.size();

        vector<int> color(lg, -1), area;
        for (int i = 0, cc = 0; i < lg; i++) {
            if (color[i] == -1) {
                area.push_back(dfs(graph, color, i, cc++));
            }
        }
        map<int, map<int, vector<int>>, greater<int>> hm;
        for (int i : initial) {
            int c = color[i];
            hm[area[c]][c].push_back(i);
        }

        for (auto& ir : hm) 
            for (auto& cr : ir.second) 
                if (cr.second.size() == 1) 
                    return cr.second[0];    

        return *min_element(initial.begin(), initial.end());
    }
};


