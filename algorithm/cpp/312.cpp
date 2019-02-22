class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        for (int len = 1; len <= n; len++) {
            for (int start = 1, end = len; end <= n; start++, end++) {
                for (int mid = start; mid <= end; mid++) {
                    dp[start][end] = max(dp[start][end], dp[start][mid-1] + nums[start-1]*nums[mid]*nums[end+1] + dp[mid+1][end]);            
                }
            }
        }
        return dp[1][n];
    }
};
