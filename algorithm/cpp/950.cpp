
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int ld = (int)deck.size();
        queue<int> q;
        for (int i = 0; i < ld; i++)
            q.push(i);
        sort(deck.begin(), deck.end());
        vector<int> ans(ld);
        for (int i = 0; q.size() > 1; i++) {
            ans[q.front()] = deck[i]; q.pop();
            q.push(q.front()); q.pop();
        }
        ans[q.front()] = deck[ld-1];
        return ans;
    }
};
