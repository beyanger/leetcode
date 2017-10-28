
class Solution {
    bool match(const char *s, const char *p) {
        const char *last_s = 0, *last_p = 0;

        while (*s) {
            if (*p == '*') {
                p++;
                if (*p == '\0') return true;
                last_s = s;
                last_p = p;
            } else if (*p == '?' || *p == *s) {
                s++; p++;
            } else if (last_s) {
                p = last_p;
                s = ++last_s;
            } else {
                return false;
            }
        }
        while (*p == '*') p++;
        return *p == '\0';
    }
public:
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
};
