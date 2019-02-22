
class Solution {
public:
    int jump(vector<int>& nums) {
        int ln = nums.size() - 1;
        int step, i, cr;
        for (step = i = cr = 0; cr < ln; step++) {
            int pre = cr;
            for (; i <= pre; i++)
                cr = max(cr, i + nums[i]);
        }
        return step;
    }
};
