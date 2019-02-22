
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int h = A.size(), w = A[0].size();
        vector<int> cnt(w);
        for (int i = 0; i < h; i++) {
            if (A[i][0] == 0) 
                for (int& a : A[i]) a = !a;
            for (int j = 1; j < w; j++)
                cnt[j] += A[i][j];
        }
        int ans = h * pow(2, w-1);
        for (int j = 1; j < w; j++)
            ans += max(cnt[j], h-cnt[j]) * pow(2, w-j-1);
        return ans;
    }
};

