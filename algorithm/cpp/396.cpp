
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int cr = 0, sum = 0;
        int la = (int)A.size();
        for (int i = 0; i < la; i++) {
            sum += A[i];
            cr += i *A[i];
        }
        int ans = cr;
        for (int i = 0; i < la; i++) {
            cr += la*A[i] - sum;
            ans = max(cr, ans);
        }
        return ans;
    }
};
