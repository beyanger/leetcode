class Solution {
    unordered_map<long, bool> m_;
    unordered_map<int, int> index_;

    bool dfs(const vector<int>& stones, int cr, int step) {
        union {
            struct { int a, b; };
            long k;
        } t = {{cr, step}};
        if (cr == stones.size()-1) return true;
        if (m_.count(t.k)) return false;

        for (int i = max(1, step-1); i <= step+1; i++) {
            int next = stones[cr] + i;
            if (index_.count(next)) {
                if (dfs(stones, index_[next], i)) {
                    return true;
                }
            }
        }
        return m_[t.k] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        int ls = stones.size();
        for (int i = 0; i < ls; i++)
            index_[stones[i]] = i;
        return dfs(stones, 0, 0);
    }
};
