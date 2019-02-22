class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        string ns;
        vector<int> cnt;
        int lens = S.size();
        for (int i = 0; i <lens;) {
            int j = i++;
            while (i < lens && S[j] == S[i]) i++;
            ns.push_back(S[j]);
            cnt.push_back(i-j);
        }
        lens = ns.size();
        int ans = 0;
        for (string w : words) {
            int i = 0, k = 0, lw = w.size();
            for (;i < lw && k < lens; k++) {
                if (ns[k] != w[i]) break;
                int j = i++;
                while (i < lw && w[j] == w[i]) i++;
                int cr = i-j;
                if (cr > cnt[k]) break;
                if (cnt[k] < 3 && cnt[k] != cr)
                    break;
            }
            if (i == lw && k == lens) ans++;
        }
        return ans;
    }
};


