
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<array<int, 2>> sk;
        for (string& ls : logs) {
            const char *l = ls.c_str();
            while (*l++ != ':');
            bool isstart = *l++ == 's';
            while (*l++ != ':');
            int tim = atoi(l);
            if (isstart) {
                sk.push({tim, 0});
            } else {
                int id = atoi(ls.c_str());
                array<int, 2> tp = sk.top(); sk.pop();
                int span = tim - tp[0] + 1;
                ans[id] += (span - tp[1]);
                if (!sk.empty()) {
                    sk.top()[1] += span;
                }
            }
        }
        return ans;
    }
};

