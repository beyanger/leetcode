
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int rest = 0, hold = INT_MIN, sold = 0;
        for (int price : prices) {
            int pre_hold = hold;
            hold = max(hold, rest-price); //hold
            rest = max(rest, sold); // rest
            sold = pre_hold + price; // sold
        }
        return max(rest, sold);
    }
};

