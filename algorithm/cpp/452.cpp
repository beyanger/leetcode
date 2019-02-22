
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() <= 1) return (int)points.size();
        sort(points.begin(), points.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        int still = (int)points.size(), left = INT_MIN;
        for (pair<int, int>& p : points) {
            if (left < p.first) left = p.second;
            else still--;
        }
        return still;
    }
};
