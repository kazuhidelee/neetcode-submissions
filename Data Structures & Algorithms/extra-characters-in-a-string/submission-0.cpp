class Solution {
public:
    struct TrieNode{
        bool end = false;
        unordered_map<char, TrieNode*> neighbors;
    };

    TrieNode* head = new TrieNode();

    void add_word(string &word){
        TrieNode* ptr = head;
        for(char c: word){
            if(!ptr->neighbors.count(c)){
                ptr->neighbors[c] = new TrieNode();
            }
            ptr = ptr->neighbors[c];
        }
        ptr->end = true;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for(string word: dictionary){
            add_word(word);
        }
        vector<int> dp(s.length() + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < s.length(); ++i){
            TrieNode* ptr = head;
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            for(int j = i; j < s.length(); ++j){
                if(ptr->neighbors.count(s[j])){
                    ptr = ptr->neighbors[s[j]];
                }else{
                    break;
                }

                if(ptr->end){
                    dp[j + 1] = min(dp[i], dp[j + 1]);
                }
            }
        }
        
        return dp[s.length()];
    }
};