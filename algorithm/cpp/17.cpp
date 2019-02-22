class Solution {
    const string step[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(string& digits, string& cr, int i) {
        if (i == digits.size()) {
            ans.push_back(cr); return;
        }
        for (char c : step[digits[i] - '2']) {
            cr[i] = c;
            dfs(digits, cr, i+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        string cr(digits.size(), ' ');
        dfs(digits, cr, 0);
        return ans;
    }
};
