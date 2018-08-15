class Solution {
    unordered_map<string, vector<string>> dp;

    vector<string> append(vector<string>& ans, string& right) {
        vector<string> res;
        for (string& str : ans) res.push_back(str + " " + right);
        return res;
    }

    vector<string>& wordBreak(string s, unordered_set<string>& wd) {
        if (dp.count(s)) return dp[s];
        vector<string> ans;
        if (wd.count(s)) ans.push_back(s);
        for (int i = 1; i < s.size(); i++) {
            string right = s.substr(i);
            if (wd.count(right) == 0) continue;
            string left = s.substr(0, i);
            vector<string> res = append(wordBreak(left, wd), right);
            ans.insert(ans.end(), res.begin(), res.end());
        }
        dp[s].swap(ans);
        return dp[s];
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        return wordBreak(s, wd);
    }
};
