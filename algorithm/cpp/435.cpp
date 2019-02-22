
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& it) {
        sort(it.begin(), it.end(), [](Interval& a, Interval&b) {
            return a.end < b.end;
        });
        int ans = 0, left = INT_MIN;
        for (Interval& i : it) {
            if (left <= i.start) left = i.end;
            else ans++;
        }
        return ans;
    }
};
