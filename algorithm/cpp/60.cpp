
class Solution {
public:
	string getPermutation(int n, int k) {
		const static int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
		const static char *s = "123456789";

		string str(s, s+n);
		k--;
		string res = "";
		for (int i = n-1; i >= 0; i--) {
			int m = (k / fact[i]);
			k  %= fact[i];
			res.push_back(str[m]);
			str.erase(str.begin()+m);
		}

		return res;
	}
};


