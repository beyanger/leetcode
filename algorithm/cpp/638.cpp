
class Solution {

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& nd) {
        int dp[7][7][7][7][7][7] = {};
        int a, b, c, d, e, f;
        int lp = price.size();
        if (lp < 6) {
            vector<int> it(6-lp);
            price.insert(price.begin(), it.begin(), it.end());
            nd.insert(nd.begin(), it.begin(), it.end());
            for (vector<int>& sp : special)
                sp.insert(sp.begin(), it.begin(), it.end());
        }
        for (a=0; a <= nd[0]; a++)
        for (b=0; b <= nd[1]; b++)
        for (c=0; c <= nd[2]; c++)
        for (d=0; d <= nd[3]; d++)
        for (e=0; e <= nd[4]; e++)
        for (f=0; f <= nd[5]; f++)
            dp[a][b][c][d][e][f] =
                a*price[0] + b*price[1] + c*price[2] + d*price[3] + e*price[4] + f*price[5];

        for (vector<int>& s : special)
            for (a=s[0]; a <= nd[0]; a++)
            for (b=s[1]; b <= nd[1]; b++)
            for (c=s[2]; c <= nd[2]; c++)
            for (d=s[3]; d <= nd[3]; d++)
            for (e=s[4]; e <= nd[4]; e++)
            for (f=s[5]; f <= nd[5]; f++)
                dp[a][b][c][d][e][f] = min(dp[a][b][c][d][e][f],
                    dp[a-s[0]][b-s[1]][c-s[2]][d-s[3]][e-s[4]][f-s[5]] + s[6]);
        return dp[nd[0]][nd[1]][nd[2]][nd[3]][nd[4]][nd[5]];
    }
};
