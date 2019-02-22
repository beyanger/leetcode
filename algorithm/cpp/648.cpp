
class Solution {

    class TrieTree {
        struct TrieNode {
            TrieNode *next[26] = {0};
            string str;
            bool isWord = false;
        };

        TrieNode *root = new TrieNode();

        void free(TrieNode *node) {
            for (TrieNode *next : node->next) {
                if (next) free(next);
            }
            delete node;
        }

    public:
        /** Initialize your data structure here. */
        ~TrieTree() {
            free(root);
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode *node = root;
            for (char c : word) {
                TrieNode *& tmp = node->next[c-'a'];
                if (!tmp) tmp = new TrieNode();
                node = tmp;
            }
            node->isWord = true;
            node->str = word;
        }

        /** Returns the prefix if word's prefix is in the trie or origin word. */
        string search(string word) {
            TrieNode *node = root;
            for (char c : word) {
                node = node->next[c-'a'];
                if (!node) return word;
                if (node->isWord) return node->str;
            }
            return word;
        } 
    };

public:
    string replaceWords(vector<string>& dict, string sentence) {
        stringstream out(sentence), in;
        TrieTree tr;
        for (string& s : dict) tr.insert(s);

        string t;
        while (out >> t) {
            in << tr.search(t);
            if (!out.eof())
                in << " ";
        }
        return in.str();
    }
};

