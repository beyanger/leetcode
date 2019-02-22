class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int ans = duration, lt = timeSeries.size();
        for (int i = 1; i < lt; i++) 
            ans += min(timeSeries[i]-timeSeries[i-1], duration);
        return ans;
    }
};

