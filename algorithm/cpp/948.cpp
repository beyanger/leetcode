
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());

        int i = 0, j = tokens.size();
        int ans = 0, cr = 0;
        while (i < j) {
            while (i < j && P >= tokens[i]) {
                cr++; P -= tokens[i++]; 
            }
            ans = max(ans, cr);
            if (cr == 0 || i == j) break;
            cr--; P += tokens[--j];
        }
        return ans;
    }
};
