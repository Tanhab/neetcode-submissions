class PrefixTree {
    struct Node{
        vector<Node*> letters{26,nullptr};
        bool isEnd = false;
    };
public:
    Node* root;
    PrefixTree() {
         root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->letters[ch-'a'] == nullptr)
                temp->letters[ch-'a'] = new Node();
            temp = temp->letters[ch-'a'];
        }
        temp->isEnd = true;

    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch: word){
            if(temp->letters[ch-'a'] == nullptr)
                return false;
            temp = temp->letters[ch-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch: prefix){
            if(temp->letters[ch-'a'] == nullptr)
                return false;
            temp = temp->letters[ch-'a'];
        }
        return true;
    }
};
