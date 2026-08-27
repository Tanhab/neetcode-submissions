class WordDictionary {
    struct Node {
        unordered_map<char, Node*> children;
        bool isWord = false;
    };
    Node* root;

   public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* temp = root;
        for (char ch : word) {
            if (!temp->children.contains(ch)) temp->children[ch] = new Node();
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }
    bool dfs(Node* cur, int i, string& word) {
        if (i == word.size()) return cur->isWord;
        if (word[i] == '.') {
            bool b = false;
            for (auto& [ch, node] : cur->children) {
                b |= dfs(node, i + 1, word);
            }
            return b;
        } else {
            if (!cur->children.contains(word[i])) {
                return false;
            }
            return dfs(cur->children[word[i]], i + 1, word);
        }
    }

    bool search(string word) { 
        return dfs(root, 0, word); }
};
