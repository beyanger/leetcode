class Solution {
public:
    string reorganizeString(string S) {
        int half = (S.size() + 1) / 2;
        int cnt[128] = {};
        for (char c : S)
            if (++cnt[c] > half) return "";

        priority_queue<pair<int, char>> q;
        for (int i = 'a'; i <= 'z'; i++)
            if (cnt[i]) q.push({cnt[i], i});

        string ans;
        while (q.size() > 1) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            ans.push_back(t1.second);
            ans.push_back(t2.second);
            if (--t1.first) q.push(t1);
            if (--t2.first) q.push(t2);
        }
        if (!q.empty())
            ans.push_back(q.top().second);

        return ans;
    }
};

