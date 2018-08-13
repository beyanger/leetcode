class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int ans = 0;
        int n = height.size();
        vector<int> left(n), right(n);
        left[1] = height[0];
        for (int i = 2; i < n; i++) {
            left[i] = max(left[i-1], height[i-1]);
        }

        right[n-2] = height[n-1];
        for (int i = n-3; i >= 0; i--) {
            right[i] = max(right[i+1], height[i+1]);
        }
        for (int i = 1; i <= n-2; i++) {
            ans += max(0, min(left[i], right[i])-height[i]); 
        }

        return ans;
    }
};
