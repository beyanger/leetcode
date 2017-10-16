
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> xx;
		for (int n : nums) xx[n]++;
		vector<pair<int, int>> v;
		for (auto itr = xx.begin(); itr != xx.end(); itr++) 
			v.push_back(make_pair(itr->first, itr->second));
		sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
				return a.second > b.second;
			});
		vector<int> res;
		for (int i = 0; i < k; i++)
			res.push_back(v[i].first);
		return res;
	}
};
