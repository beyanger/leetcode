
class Solution {
    bool match_star(const char c, const char *s, const char *p) {
        do {
            if (match(s, p)) return true;
        } while (*s && (*s++ == c || c=='.'));
        return false;
    }

    bool match(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        if (p[1] == '*') return match_star(*p, s, p+2);
        return *s && (*p=='.' || *p==*s) && match(s+1, p+1);
    }

public:
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }
};
