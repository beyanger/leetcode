
class WordDictionary {
	struct TrieNode {
		TrieNode *next[26] = {0};
		bool isExist = false;
	} root;

public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode *node = &root;
		for (char c : word) {
			TrieNode *& tmp = node->next[c-'a'];
			if (!tmp) tmp = new TrieNode();
			node = tmp;
		}
		node->isExist = true;
	}
private:
	bool search(string& word, int si, TrieNode *node) {
		for (int i = si; i < word.size(); i++) {
			char &c = word[i];
			if (c == '.') {
				for (TrieNode *n : node->next) {
					if (n && search(word, i+1, n))
						return true;
				}
				return false;
			} else {
				node = node->next[c-'a'];
				if (!node) return false;
			}
		}
		return node->isExist;
	}
public:
	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word, 0, &root);
	}
};

