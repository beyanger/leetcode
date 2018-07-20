
class Solution {
public:
    struct PV {
        int v;
        int p;
    };
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int sz = (int)B.size();
        vector<PV> bb(sz);
        for (int i = 0; i < sz; i++) {
            bb[i] = {B[i], i};
        }
        sort(bb.begin(), bb.end(), [](const PV& x, const PV& y)
                { return x.v < y.v; });
        sort(A.begin(), A.end());
        vector<int> res(sz, -1);

        for (int i = 0, j = 0; i < sz && j < sz; i++) {
            if (A[i] > bb[j].v) {
                res[bb[j].p] = A[i];
                A[i] = -1;
                j++;
            }
        }

        for (int i = 0, j = 0; i < sz; i++) {
            if (A[i] != -1) {
                while (res[j] != -1) {
                    j++;
                }
                res[j] = A[i];
            }
        }

        return res;
    }
};
