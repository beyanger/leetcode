
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<vector<double>> worker;

        for (size_t i = 0; i < wage.size(); i++) {
            worker.push_back({(double)wage[i]/quality[i], (double)quality[i]});
        }
        sort(worker.begin(), worker.end());

        priority_queue<int> qua;
        int total_quality = 0;
        double ans = 1.0e200;
        for (vector<double>& wk : worker) {
            total_quality += (int)wk[1];
            qua.push((int)wk[1]);

            if (qua.size() > K) {
                total_quality -= qua.top();
                qua.pop();
            }
            if (qua.size() == K) 
                ans = min(ans, total_quality * wk[0]);
        }
        return ans;
    }
};
