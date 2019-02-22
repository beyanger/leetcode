
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, vector<int>> hn;
        int k = nums.size();
        for (int i = 0; i < k; i++) {
            for (int n : nums[i]) 
                hn[n].push_back(i);
        }

        int cr = 0;
        vector<int> kn(k);
        int start = hn.begin()->first, end = hn.rbegin()->first;
        int orig_diff = end - start;
        for (auto ib = hn.begin(), ir = hn.begin(); ir != hn.end(); ir++) {
            for (int n : ir->second) 
                if (kn[n]++ == 0) cr++;
            while (cr >= k) {
                int diff = ir->first - ib->first;
                if (diff < orig_diff) {
                    start = ib->first; end = ir->first;
                    orig_diff = diff;
                }
                for (int n : ib->second) 
                    if (--kn[n] == 0) cr--;
                ib++;
            }
        }
        return {start, end};
    }
};
