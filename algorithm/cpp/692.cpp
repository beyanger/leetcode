
class Solution {
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first!= b.first) return a.first < b.first;
            return a.second > b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> w;
        for (string& s :words) w[s]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;

		for (auto& ir : w)
            q.push({ir.second, ir.first});

        vector<string> res;
        while (k--) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

