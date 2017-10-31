

class Solution {
    stack<int> num;
    stack<char> syn;
    void cal() {
        while (!syn.empty() && syn.top()!='(') {
            int n1 = num.top(); num.pop();
            int n2 = num.top(); num.pop();
            char c = syn.top(); syn.pop();
            int res = c=='+' ? (n2+n1) : (n2-n1);
            num.push(res);
        }
    }
public:
    int calculate(string s) {
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+' || s[i]=='-' || s[i] == '(') {
                syn.push(s[i]); i++;
            } else if (s[i] == ')') {
                cal();
                syn.pop();
                cal();             
                i++;
            } else {
                int n = 0;
                for (; '0' <= s[i] && s[i]<='9'; i++) 
                    n = n*10 + s[i]-'0';
                num.push(n);
                cal();
            }
        }
        return num.top();
    }
};

