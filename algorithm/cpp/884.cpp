
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        vector<string> str = {""};
        vector<int> cnt = {0};
        vector<int> step = {0};
        int current = 0;
        for (size_t i = 0; i < S.size();) {
            if (islower(S[i])) {
                string t;
                while (islower(S[i])) 
                    t.push_back(S[i++]);
                current += t.size();
                if (current >= K) 
                    return t.substr(t.size()-1-(current-K),1);
                str.push_back(t);
                step.push_back(current);
            } else {
                while (isdigit(S[i])) {
                    current *= (S[i++] - '0');
                    if (current >= K) {
                        for (size_t j = step.size()-1; j > 0; j--) {
                            K %= step[j];
                            if (K == 0) K = step[j];
                            if (K > cnt[j-1]) {
                                return str[j].substr(K-cnt[j-1]-1,1);
                            }
                        }
                    }
                }
                cnt.push_back(current);
            }
        }
        return "";
    }
};


// from uwi 
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        vector<long> dp(n+1);

        for (int i = 0; i < n; i++) {
            if ('2' <= S[i] && S[i] <= '9') {
                dp[i+1] = dp[i] * (S[i] - '0');
            } else {
                dp[i+1] = dp[i] + 1;
            }
        }
        K--;
        for (int i = n-1; i >= 0; i--) {
            K %= dp[i+1];
            if (K+1 == dp[i+1] && !('2' <= S[i] && S[i] <= '9')) {
                return S.substr(i, 1);
            }
        }
        return "";
    }
};

