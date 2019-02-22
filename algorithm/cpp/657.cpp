
class Solution {
public:
    bool judgeCircle(string moves) {
        int stat[128] = {};
        for (char step : moves)
            stat[step]++;
        return stat['L']==stat['R'] && stat['D']==stat['U'];
    }
};

