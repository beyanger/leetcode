
class Solution {
    void init() {
        bool dp[350] = {};
        for (int i = 2; i < 350; i++) {
            if (dp[i]) continue;
            prim.push_back(i);
            for (int j = i+i; j < 350; j+=i) 
                dp[j] = true; 
        }
    }
    
    vector<int> getfact(int n) {
        vector<int> fact;
        for (int p : prim) {
            if (p*p > n) break;
            if (n%p == 0) {
                fact.push_back(p);
                while (n%p == 0) n /= p;
            }
        }
        if (n != 1) {
            prim.push_back(n);
            fact.push_back(n);
        }
        return fact;
    }

    vector<int> prim;
    int father[100001] = {};
    int cnt[100001] = {};

    int find(int a) {
        if (father[a] == a) return a;
        return father[a] = find(father[a]);
    }
public:
    int largestComponentSize(vector<int>& A) {
        init();
        for (int a : A) {
            vector<int> fact = getfact(a);
            if (fact.empty()) continue;
            for (int f : fact) 
                if (father[f] == 0) father[f] = f;
            cnt[find(fact[0])]++;
            for (int i = 1; i < fact.size(); i++) {
                if (father[fact[i-1]] != find(fact[i])) {
                    cnt[father[fact[i]]] += cnt[father[fact[i-1]]];
                    father[father[fact[i-1]]] = father[fact[i]];
                }
            }
        }
        int ans = 0;
        for (int p : prim) 
            ans = max(ans, cnt[p]);
        return ans;
    }
};
