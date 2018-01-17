
class Solution {
public:
    vector<int> partitionLabels(string S) {
		vector<int> ans;
		vector<int> last(26);

		for (int i = 0; i < S.size(); i++)
			last[S[i] - 'a'] = i;

		for (int i = 0; i < S.size(); i++) {
			int j = i;
			int end = last[S[i]-'a'];
			for (; i < end; i++) {
				end = max(end, last[S[i]-'a']);
			}
		
			ans.push_back(end - j + 1);
		}
		
		return ans;
	}
};
