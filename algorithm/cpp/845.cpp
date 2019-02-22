
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<int> l(n, 1), r(n, 1);
        for (int i = 1, j = n-2; i < n; i++, j--) {
            if (A[i] > A[i-1]) l[i] = l[i-1] + 1;
            if (A[j] > A[j+1]) r[j] = r[j+1] + 1;
        }
        int ans = 0;
        for (int i = n-2; i > 0; i--) {
            if (l[i] > 1 && r[i] > 1) {
                ans = max(ans, l[i]+r[i]-1);
            }
        }
        return ans;
    }
};


