class WordDictionary {
public:
    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        bool is_complete;
    };
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* ptr = WordDictionary::root;
        for(char c: word){
            if(!ptr->children.count(c)){
                ptr->children[c] = new TrieNode();
            }
            ptr = ptr->children[c];
        }
        ptr->is_complete = true;
    }
    
    bool dfs(string word, int index, TrieNode* node){
        if(index == word.length()){
            return node->is_complete;
        }
        if(word[index] == '.'){
            for(auto child: node->children){
                if(dfs(word, index + 1, child.second)) return true;
            }
            return false;
        }else{
            if(!node->children.count(word[index])) return false;
            return dfs(word, index + 1, node->children[word[index]]);
        }
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
