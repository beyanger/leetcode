
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, ls = s.size();
        vector<vector<int>> freq(26);
        for (int i = 0; i < ls; i++) {
            freq[s[i]-'a'].push_back(i);
        }
        vector<int> least = {-1};
        for (vector<int>& f : freq) {
            if (f.empty() || f.size() >= k) continue;
            least.insert(least.end(), f.begin(), f.end());
        }
        if (least.size() == 1)  return s.size();
        sort(least.begin(), least.end());
        least.push_back(ls);
        int ll = least.size();
        for (int i = 1; i < ll; i++) {
            int start = least[i-1] + 1;
            int end = least[i];
            if (end-start >= k)
                ans = max(ans, longestSubstring(s.substr(start, end-start), k));
        }
        return ans;
    }
};
