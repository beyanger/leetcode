
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size()-1, cr = 0; i >= 0; i--) {
            cr += shifts[i] % 26;
            S[i] = (S[i] - 'a' + cr) % 26 + 'a';
        }

        return S;
    }
};
