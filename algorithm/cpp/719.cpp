
class Solution {
    int findp(vector<int>& v, int m) {
        int s = 0, j = 0;
        for (int i = 0; i < v.size(); i++) {
            while (j < v.size() && v[j]-v[i] <= m) j++;
            s += j - i - 1;
        }
        return s;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back()-nums.front();

        while (l < r) {
            int m = (l + r) / 2;
            int s = findp(nums, m);
            if (s >= k) r = m;
            else l = m+1;
        }
        return l;
    }
};
