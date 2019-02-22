class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ln = nums.size(), reached = 0;
        for (int i = 0;  i < ln; i++) {
            if (i > reached) return false;
            reached = max(reached, nums[i] + i);
        }
        return true;
    }
};
