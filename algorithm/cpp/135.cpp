
class Solution {
public:
	int candy(vector<int>& ratings) {
		int size = ratings.size();
		vector<int> can(size, 1);

		for (int j = 0, i = 1; i < size; i++, j++) {
			if (ratings[i] > ratings[j]) can[i] = can[j]+1;
		}

		for (int i = size-2, j = size-1; i >= 0; i--, j--) {
			if (ratings[i] > ratings[j]) can[i] = max(can[i], can[j]+1);
		}

		return accumulate(can.begin(), can.end(), 0);
	}
};

