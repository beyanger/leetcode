
class Solution {
    int ans = INT_MAX;

    void replace(long n, int cr) {
        if (cr >= ans) return;
        if (n %2 == 0) return replace(n/2, cr+1);
        if (n == 1) {
            ans = min(ans, cr); return;
        }
        replace(n-1, cr+1);
        replace(n+1, cr+1);
    }
public:
    int integerReplacement(int n) {
        replace(n, 0);
        return ans;
    }
};

