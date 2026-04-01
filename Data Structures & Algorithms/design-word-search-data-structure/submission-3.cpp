class Node {
public:
    unordered_map<char,Node*> m;
    Node() {
    }
};

class WordDictionary {
public:
    Node* head;
    WordDictionary() {
        this->head = new Node();
    }
    
    void addWord(string word) {
        // loop until end, add end char
        Node* curr = this->head;
        for (auto c : word) {
            if (!curr->m.count(c)) {
                curr->m[c] = new Node();            
            }
            curr = curr->m[c];
        }
        curr->m['\0'] = nullptr;
    }
    
    bool search(string word) {
        Node* curr = this->head;
        return searchUsingNode(word, curr);
    }
private:
    bool searchUsingNode(string word, Node* curr) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto [c, nextNode] : curr->m) {
                    if (c != '\0' && searchUsingNode(word.substr(i+1), nextNode)) return true;
                }
                return false;
            } else if (!curr->m.contains(word[i])) {
                return false;
            }
            curr = curr->m[word[i]];
        }
        if (curr->m.contains('\0')) {
            return true;
        }
        return false;
    }
};
