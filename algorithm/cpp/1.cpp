
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mn;
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            if (mn.count(left)) 
                return {mn[left], i};
            mn[nums[i]] = i;
        }

        return {};
    }
};
