
class Solution {
public:
    bool judgeCircle(string moves) {
        int stat[128] = {0};
        for (char step : moves)
            stat[step]++;
        return stat['L']==stat['R'] && stat['D']==stat['U'];
    }
};

