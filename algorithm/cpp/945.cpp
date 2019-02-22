
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int dp[40001] = {}, me = 0, ans = 0;

        for (int a : A) {
            dp[a]++;
            me = max(me, a);
        }
        for (int i = 0; i < me; i++) {
            if (dp[i] <= 1) continue; 
            dp[i+1] += dp[i]-1;
            ans += dp[i]-1;
        }
        return ans + dp[me]*(dp[me]-1)/2;
    }
};
