
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty()) return 0;
        int lp = (int)position.size(), ans = 0;
        vector<array<int, 2>> sp;
        for (int i = 0; i < lp; i++) {
            sp.push_back({position[i], speed[i]});
        }
        sort(sp.begin(), sp.end());
        float last = 0.;
        while (--lp >= 0) {
            float cr = (float)(target - sp[lp][0]) / sp[lp][1];
            if (cr > last) {
                last = cr;
                ans++;
            }
        } 
        return ans;
    }
};

