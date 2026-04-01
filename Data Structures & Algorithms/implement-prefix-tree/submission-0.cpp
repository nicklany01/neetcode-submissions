class TrieNode {
    public:
        unordered_map<char, TrieNode*> nextC;
        bool isEnd = false;
        char c;
        
        TrieNode (char c_param) {
            c = c_param;
        }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            // if there is a char in the nextC then go to the next TrieNode, else add one.
            curr->nextC.try_emplace(c, new TrieNode(c));
            curr = curr->nextC[c];
            cout << curr->c;
            
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->nextC.contains(c)) {
                return false;
            }
            curr = curr->nextC[c];
        }
        if (curr->isEnd) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (!curr->nextC.contains(c)) {
                return false;
            }
            curr = curr->nextC[c];
        }
        return true;
    }
};
