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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto is = intervals;
        int i;
        for (i = is.size()-1; i >= 0; i--) {
            if (is[i].start <= newInterval.start) break;
        }

        is.insert(is.begin()+i+1, newInterval);

        for (i = 1; i < is.size();) {
            if (is[i-1].end >= is[i].start) {
                is[i-1].end = max(is[i-1].end, is[i].end);
                is.erase(is.begin()+i);
            } else {
                i++;
            }
        }

        return is;
    }
};
