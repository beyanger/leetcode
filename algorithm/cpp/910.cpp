
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int len = A.size();
        int ans = A[len-1] - A[0];
        for (int i = 1; ans && i < len; i++) {
            int upper = max(A[len-1]-K, A[i-1]+K);
            int lower = min(A[i]-K, A[0]+K);
            ans = min(ans, upper-lower);
        }
        return ans;
    }
};
