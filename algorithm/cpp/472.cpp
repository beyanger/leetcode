
class Solution {

    bool dfs(unordered_set<string>& wd, string str) {
        if (str.size() == 0 || wd.count(str)) return true;
        for (int i = 1; i < str.size(); i++) {
            if (wd.count(str.substr(0, i)) && dfs(wd, str.substr(i)))
                return true;
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.empty()) return {};

        unordered_set<string> wd;
        vector<string> ans;
        sort(words.begin(), words.end(), [](const string &a, const string& b) {
            return  a.size() < b.size();
        });

        for (string& w : words) {
            if (w.size() > 0 && dfs(wd, w)) {
                ans.push_back(w);
            }
            wd.insert(w);
        }

        return ans;
    }
};
