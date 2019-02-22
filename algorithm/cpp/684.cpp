class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(edges.size()+1);
        for (int i = 1; i < parent.size(); i++) parent[i] = i;
        for (vector<int>& e : edges) {
            int pu = findparent(parent, e[0]);
            int pv = findparent(parent, e[1]);
            if (pu == pv) return e;
            parent[pu] = pv;
        }
        return {};
    }
    int findparent(vector<int>& parent, int k) {
        while (k != parent[k]) 
            k = parent[k];
        return k;
    }
};
