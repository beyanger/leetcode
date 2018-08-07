
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        const int MOD = 1e9 + 7;

        long lcm = lowest_common_multiple(A, B);
        int step = lcm/A + lcm/B - 1;
        int lm = N / step;
        int left = N % step;

        long sa = (long)lm * lcm % MOD;
        long sb = sa;
        while (left-- > 0) {
            if ((sa + A) < (sb + B))
                sa += A;
            else
                sb += B;
        }
        return max(sa, sb) % MOD;
    }

long lowest_common_multiple(int m, int n) {
    int r, m1 = m, n1 = n;

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return (long)m1 * n1 / m;
}
};
