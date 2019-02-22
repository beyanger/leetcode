
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> q;
        for (int n : nums) freq[n]++;
        for (auto& r : freq) q.push({r.second, r.first});
        vector<int> ans;
        while (k-- > 0) {
            ans.push_back(q.top().second); q.pop();
        }
        return ans;
    }
};

