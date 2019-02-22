class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int la = A.size(), n = 0;
        for (int a : A)  n += a;
        if (n == 0) return {0, la-1};
        if (n % 3 != 0) return {-1, -1};
        n /= 3;
        vector<int> p;
        for (int i = 0, c = 0; i < la; i++) {
            if (A[i] == 1) {
                if (c++ % n == 0) p.push_back(i);
            }
        }
        int i = p[0], j = p[1], k = p[2];
        for (; k < la; i++, j++, k++) {
            if (A[i] == A[j] && A[i] == A[k]) continue;
            return {-1, -1};
        }
        return {i-1, j};
    }
};

