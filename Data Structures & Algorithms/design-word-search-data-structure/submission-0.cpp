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
    
    // bool dfs()

    bool search(string word) {
        queue<TrieNode*> bfs;
        bfs.push(WordDictionary::root);
        int index = 0;
        while(index < word.length()){
            int n = bfs.size();
            for(int i = 0; i < n; ++i){
                TrieNode* curr = bfs.front();
                bfs.pop();
                if(word[index] != '.' && !curr->children.count(word[index])) continue;
                if(word[index] == '.'){
                    for(auto child: curr->children){
                        bfs.push(child.second);
                    }
                }else{
                    bfs.push(curr->children[word[index]]);
                }
            }
            index++;
        }
        while(!bfs.empty()){
            if(bfs.front()->is_complete) return true;
            bfs.pop();
        }
        return false;
    }
};
