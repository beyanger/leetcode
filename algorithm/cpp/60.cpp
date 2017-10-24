
class Solution {
public:
	string getPermutation(int n, int k) {
		const static int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
		const static char *str = "123456789";

		string s(n, '0');
		for (int i = 0; i < n; i++)
			s[i] = str[i];

		k--;
		string res = "";
		for (int i = n-1; i >= 0; i--) {
			int m = (k / fact[i]);
			k  %= fact[i];
			res.push_back(s[m]);
			s.erase(s.begin()+m);
		}

		return res; 
	}
};


