
class Solution {

    bool nonzero(float a) { return !( -0.00001 < a && a < 0.00001); }

    bool valid(float a) { return (23.99999 < a && a < 24.00001); }
    bool valid(float a, float b) {
        if (valid(a+b) || valid(a-b) || valid(a*b) || nonzero(b)&&valid(a/b)) return true;
        return false;
    }
    bool valid(float a, float b, float c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || nonzero(b)&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || nonzero(c)&&valid(a, b/c)) return true;
        return false;
    }
    bool valid(float a, float b, float c, float d) {
        if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || nonzero(b)&&valid(a/b, c, d)) return true;
        if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || nonzero(c)&&valid(a, b/c, d)) return true;
        if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || nonzero(d)&&valid(a, b, c/d)) return true;
        return false;
    }

public:
    bool judgePoint24(vector<int>& num) {
        sort(num.begin(), num.end());
        do {
            if (valid(num[0], num[1], num[2], num[3])) return true;
        } while (next_permutation(num.begin(), num.end()));
        return false;
    }
};
