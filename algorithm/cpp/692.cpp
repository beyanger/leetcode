
class Solution {
    struct KV {
        string s;
        int f;
        KV(string s, int f) : s(s), f(f) {}
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> w;
        for (string& s :words) w[s]++;
        vector<KV *> v;
        for (auto itr = w.begin(); itr!=w.end(); itr++)
            v.push_back(new KV(itr->first, itr->second));
        sort(v.begin(), v.end(), [](const KV* a, const KV* b) {
                if (a->f != b->f) return a->f > b->f;
                return a->s < b->s;
                });
        vector<string> res;
        for (int i = 0; i < k; i++) 
            res.push_back(v[i]->s);
        for (auto kv : v) delete kv;
        return res;
    }
};



