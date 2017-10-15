
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') a++;
            else if (s[i]=='L' && i > 1 && s[i-1]=='L' && s[i-2]=='L') 
                return false;
        }
        return a < 2;
    }
};
