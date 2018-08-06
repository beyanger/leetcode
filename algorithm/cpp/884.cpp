
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
