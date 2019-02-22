
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0, p3 = 0;
        int last = INT_MAX;
        for (int i = 0; i < n;) {
            int j = i++;
            while (i < n && nums[j] == nums[i]) i++;
            int d = i-j;
            if (last != nums[j]-1) {
                if (p1 || p2) return false;
                p1 = d; p3 = 0;
            } else {
                d -= p1+p2;
                if (d < 0) return false;
                p3 = min(p3, d);
                d -= p3; p3 += p2; p2 = p1; p1 = d;
            }
            last = nums[j];
        }
        return p1 == 0 && p2 == 0;
    }
};

