class Solution {
    void insert(vector<int>& v, int val) {
        int i = 0, j = v.size()-1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (val > v[mid]) i = mid+1;
            else if (val < v[mid]) j = mid-1;
            else {
                v.insert(v.begin()+mid, val);
                return ;
            }
        }
        v.insert(v.begin()+i, val);
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        bool isOdd = (k%2) == 1;
        int idx = k / 2;
        vector<int> cr(nums.begin(), nums.begin()+k);
        sort(cr.begin(), cr.end());
        if (isOdd) ans.push_back((double)cr[idx]);
        else ans.push_back(((long)cr[idx]+cr[idx-1]) / 2.0);

        for (int i = k; i < nums.size(); i++) {
            cr.erase(find(cr.begin(), cr.end(), nums[i-k]));
            insert(cr, nums[i]);
            if (isOdd) ans.push_back((double)cr[idx]);
            else ans.push_back(((long)cr[idx]+cr[idx-1]) / 2.0);
        }
        return ans;
    }
};

