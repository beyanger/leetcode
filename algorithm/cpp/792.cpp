
class Solution {

public:
    int numMatchingSubseq(string S, vector<string>& words) {
        queue<const char *> waiting[128];

        for (string& w : words)
            waiting[w[0]].push(w.c_str());

        for (char c : S) {
            auto& q = waiting[c];
            for (int qs = q.size(); qs > 0; qs--) {
                auto cr = q.front(); q.pop();
                waiting[cr[1]].push(cr+1);
            }
        }
        return (int)waiting[0].size();
    }
};
