class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool complete = false;
    TrieNode(){
        complete = false;
    }
};

class PrefixTree {
public:
    TrieNode* head;
    PrefixTree() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* ptr = head;
        for(char c: word){
            if(!ptr->children.count(c)){
                ptr->children[c] = new TrieNode();
            }
            ptr = ptr->children[c];
        }
        ptr->complete = true;
    }
    
    bool search(string word) {
        TrieNode* ptr = head;
        for(char c: word){
            if(!ptr->children.count(c)){
                return false;
            }
            ptr = ptr->children[c];
        }
        if(ptr->complete) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ptr = head;
        for(char c: prefix){
            if(!ptr->children.count(c)){
                return false;
            }
            ptr = ptr->children[c];
        }
        return true;
    }
};
