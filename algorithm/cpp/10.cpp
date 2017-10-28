
class Solution {
    bool matchstar(const char c, const char *s, const char *p) {
        do {
            if (matchhere(s, p)) return true;
        } while (s[0] !='\0' && (*s++ == c || c=='.'));
        return false;
    }

    bool matchhere(const char *s, const char *p) {
        if (p[0] == '\0') return s[0] == '\0';
        if (p[1] == '*') return matchstar(p[0], s, p+2);

        if (s[0]!='\0' && (p[0]=='.' || p[0]==s[0]))
            return matchhere(s+1, p+1);
        return false;
    }

public:
    bool isMatch(string s, string p) {
        return matchhere(s.c_str(), p.c_str());
    }
};
