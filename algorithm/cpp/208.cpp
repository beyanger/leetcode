class Trie {
	struct TrieNode {
		bool isExist = false;
		TrieNode *next[26] = {0};
	};

	TrieNode root;
public:
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *node = &root;
		for (char c: word) {
			TrieNode *& tmp = node->next[c-'a'];
			if (!tmp) tmp = new TrieNode();
			node = tmp;
		}
		node->isExist = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *node = &root;
		for (char c : word) {
			node = node->next[c-'a'];
			if (!node) return false;
		}
		return node->isExist;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *node = &root;
		for (char c : prefix) {
			node = node->next[c-'a'];
			if (!node) return false;
		}
		return true;
	}
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
