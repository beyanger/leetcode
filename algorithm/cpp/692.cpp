
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> w;
        for (string& s :words) w[s]++;
        vector<pair<string, int> *> v;

		for (auto& itr : w)
            v.push_back(new pair<string, int>(itr.first, itr.second));

        sort(v.begin(), v.end(), [](const pair<string, int>* a, const pair<string, int>* b) {
                if (a->second != b->second) return a->second > b->second;
                return a->first < b->first;
                });
        vector<string> res;
        for (int i = 0; i < k; i++) 
            res.push_back(v[i]->first);
        for (auto kv : v) delete kv;
        return res;
    }
};



