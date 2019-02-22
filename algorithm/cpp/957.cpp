
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int cr = 0, next;
        for (int i = 0; i < 8; i++) 
            cr |= (cells[i] << i);

        vector<int> visited(256, -1), step(256);

        for (int days=0; days < N; days++) {
            if (visited[cr] >= 0) {
                cr = step[visited[cr] + (N-days)%(days-visited[cr])];
                break;
            }
            visited[cr] = days;
            step[days] = cr;

            next = 0;
            for (int i = 1; i < 7; i++) {
                int side = (cr >> (i-1)) & 0x5;
                if (side == 0 || side == 5) 
                    next |= (1 << i);
                else 
                    next &= ~(1 << i);
            }
            cr = next;
        }

        for (int i = 0; i < 8; i++) 
            cells[i] = (cr >> i) & 1;
        return cells;
    }
};
