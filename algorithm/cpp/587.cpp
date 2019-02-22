
bool operator<(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int cross(const Point& a, const Point& b, const Point& c) {
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& p) {
        if (p.size() < 4) return p;

        sort(p.begin(), p.end());

        vector<Point> u, l;
        for (Point& t : p) {
            for (int n = u.size(); n > 1 && cross(u[n-2], u[n-1], t) < 0; n--) 
                u.pop_back();
            u.push_back(t);
        }
        for (int i = p.size()-1; i >= 0; i--) {
            for (int n = l.size(); n > 1 && cross(l[n-2], l[n-1], p[i]) < 0; n--)
                l.pop_back();
            l.push_back(p[i]);
        }

        u.insert(u.end(), l.begin()+1, l.end()-1);
        return u;
    }
};

