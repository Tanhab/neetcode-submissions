class Solution {
    struct Node {
        unordered_map<char, Node*> children;
        bool isWord = false;
    };
    Node* root;
    void add(string word) {
        Node* temp = root;
        for (char ch : word) {
            if (!temp->children.contains(ch)) {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }
   
    bool search(string word) {
        if (word.size() == 0) return false;
        Node* temp = root;
        for (char ch : word) {
            if (!temp->children.contains(ch)) return false;
            temp = temp->children[ch];
        }
        if(temp->isWord){
            temp->isWord = false;
            return true;
        }
        return temp->isWord;
    }
    bool prefix(string word){
        if (word.size() == 0) return false;
        Node* temp = root;
        for (char ch : word) {
            if (!temp->children.contains(ch)) return false;
            temp = temp->children[ch];
        }
        return true;
    }

   public:
    int n, m;
    vector<string> ans;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    void backtrack(int x, int y, string cur, vector<vector<char>>& board) {
        if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] == '#') return;
        string s = cur + board[x][y];
        if (search(s)) {
            ans.push_back(s);
        }
        if(!prefix(s)) return;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            char ch = board[x][y];

            board[x][y] = '#';
            backtrack(xx, yy, s, board);
            board[x][y] = ch;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for (string& s : words) add(s);
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                backtrack(i, j, "", board);
            }
        }
        return ans;
    }
};
