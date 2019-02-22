
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        int l1 = (int)num1.size(), l2 = (int)num2.size();
        vector<int> result(l1+l2);

        for (int i = l1-1; i >= 0; i--) {
            for (int j = l2-1; j >= 0; j--) {
                result[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        string ans(l1+l2, '0');
        for (int i = l1+l2-1; i > 0; i--) {
            result[i-1] += result[i] / 10;
            ans[i] += (result[i] % 10);
        }
        if (result[0] == 0) ans.erase(ans.begin());
        else ans[0] += result[0];
        return ans;
    }
};
