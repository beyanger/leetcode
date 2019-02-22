class Trie {
    struct TrieNode {
        TrieNode *next[26] = {};
        bool isWord = false;
    };

    void free(TrieNode *node) {
        for (TrieNode *next : node->next) {
            if (next) free(next);
        }
        delete node;
    }

    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) { }
    ~Trie() { free(root); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (char c: word) {
            TrieNode *& tmp = node->next[c-'a'];
            if (!tmp) tmp = new TrieNode();
            node = tmp;
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for (char c : word) {
            node = node->next[c-'a'];
            if (!node) return false;
        }
        return node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
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
