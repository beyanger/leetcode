
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, ln = nums.size();
        for (int i = 0; i < ln; i++) {
            int p = 1;
            for (int j = i; j >= 0; j--) {
                p *= nums[j];
                if (p < k) res++;
                else break;
            }
        }
        return res;
    }
};
