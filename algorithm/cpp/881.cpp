

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i, j, ans;

        for (ans = i = 0, j = people.size()-1; i < j; ans++, j--) {
            if ((people[i] + people[j]) <= limit) {
                i++;
            }
        }
        return ans + (i == j);
    }
};
