


class WordFilter {
	struct TrieNode {
		vector<int> weight;
		TrieNode *next[26] = {NULL};
	};

	void insert(TrieNode *tree, string& w, int weight) {
		for (char c : w) {
			tree->weight.push_back(weight);
			TrieNode *& tmp = tree->next[c-'a'];
			if (!tmp) tmp = new TrieNode();
			tree = tmp;
		}
		tree->weight.push_back(weight);
	}

	TrieNode *search(TrieNode *tree, string& w) {
		for (char c : w) {
			tree = tree->next[c-'a'];
			if (!tree)
				return NULL;
		}
		return tree;
	}
	vector<string> ws;
	TrieNode *ptree;
public:
	WordFilter(vector<string> words) : ptree(new TrieNode), ws(words) {
		for (int i = 0; i < words.size(); i++) {
			insert(ptree, words[i], i);
		}
	}
	int f(string prefix, string suffix) {
		TrieNode *p = search(ptree, prefix);
		if (!p || p->weight.empty()) return -1;
		for (int i = p->weight.size()-1; i >= 0; i--) {
			int pos = p->weight[i];
			string& s = ws[pos];
			if (s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0) 
				return pos;
		}
		return -1;
	}
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
