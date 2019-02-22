
class Solution {
    vector<vector<int>> dp_;
    vector<int> num_;

    int dfs(int n, int m) {
        if (dp_[n][m]) return dp_[n][m]; 
        int sum = 0, cr = INT_MAX;
        for (int i = n-1, e = m-1; i >= e; i--) {
            sum += num_[i];
            cr = min(cr, max(sum, dfs(i, e)));
        }
        return dp_[n][m] = cr;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; i++)
            dp[i+1][1] = dp[i][1] + nums[i];
        swap(dp, dp_);
        swap(nums, num_);
        return dfs(n, m);
    }
};

