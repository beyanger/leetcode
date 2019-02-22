class Solution {
    struct TrieNode {
        TrieNode *next[26] = {};
        bool isWord = false;
        string word;
    };

    void insert(TrieNode *node, string& word) {
        for (char c : word) {
            TrieNode *& tmp = node->next[c-'a'];
            if (!tmp) tmp = new TrieNode;
            node = tmp;
        }
        node->isWord = true;
        node->word = word;
    }

    void  search(TrieNode *node, int h, int w, int y, int x, vector<vector<char>>& board, unordered_set<string>& exists) {
        node = node->next[board[y][x]-'a'];
        if (!node) return;
        if (node->isWord) exists.insert(node->word);
        char c = board[y][x];
        board[y][x] = '\0';
        if (y > 0 && board[y-1][x])
            search(node, h, w, y-1, x, board, exists);
        if (y < h && board[y+1][x])
            search(node, h, w, y+1, x, board, exists);
        if (x > 0 && board[y][x-1])
            search(node, h, w, y, x-1, board, exists);
        if (x < w && board[y][x+1])
            search(node, h, w, y, x+1, board, exists);
        board[y][x] = c;
    }
    void free(TrieNode *node) {
        for (auto next : node->next) {
            if (next) free(next);
        }
        delete node;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode;
        for (string& word : words) insert(root, word);
        unordered_set<string> exists;
        int h = board.size(), w = board.front().size();
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                search(root, h-1, w-1, y, x, board, exists);
            }
        }
        free(root);
        return vector<string>(exists.begin(), exists.end());
    }
};

