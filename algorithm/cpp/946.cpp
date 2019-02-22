
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = -1, j = 0;
        for (int p : pushed) {
            pushed[++i] = p;
            while (i >= 0 && pushed[i] == popped[j]) {
                i--; j++;
            }
        }
        return i == -1;
};
