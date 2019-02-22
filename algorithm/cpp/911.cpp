
class TopVotedCandidate {
    vector<int> time;
    vector<int> top;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        time = move(times);
        vector<int> freq(persons.size());
        int cr = 0;
        for (int& p : persons) {
            if (++freq[p] >= freq[cr]) cr = p;
            top.emplace_back(cr);
        }
    }

    int q(int t) {
        return top[distance(time.begin(), upper_bound(time.begin(), time.end(), t))-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
