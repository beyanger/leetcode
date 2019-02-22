
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> cnt;
        int ans = 0;
        int len = (int)points.size();
        for (int i = 0; i < len; i++) {
            Point& p1 = points[i];
            cnt.clear();
            int same = 1, max_cnt = 0;
            for (int j = i+1; j < len; j++) {
                Point& p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y) same++;
                else max_cnt = max(max_cnt, ++cnt[get(p1, p2)]);
            }
            ans = max(ans, max_cnt+same);
        }
        return ans;
    }

    pair<int, int> get(Point& p1, Point& p2) {
        int dy = p1.y - p2.y;
        int dx = p1.x - p2.x;
        if (dy == 0) return {p1.x, 0};
        if (dx == 0) return {0, p1.y};
        int g = gcd(dy, dx);
        return {dy/g, dx/g};
    }
    int gcd(int m, int n) {
        return n == 0 ? m : gcd(n, m%n);
    }
};
