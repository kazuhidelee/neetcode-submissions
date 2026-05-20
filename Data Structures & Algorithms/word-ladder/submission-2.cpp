class Solution {
public:
    // bool can_transform(string s1, string s2){
    //     if(s1.length() != s2.length()) return false;
    //     int diff = 0;
    //     for(int i = 0; i < s1.length(); ++i){
    //         if(s1[i] != s2[i]){
    //             diff++;
    //         }
    //     }
    //     return diff == 1;
        
    // }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.length() != endWord.length()) return 0;
        unordered_set<string> exist;
        for(string word: wordList){
            exist.insert(word);
        }
        queue<string> dfs;
        dfs.push(beginWord);
        int steps = 1;
        while(!dfs.empty()){
            int n = dfs.size();
            for(int i = 0; i < n; ++i){
                string curr = dfs.front();
                dfs.pop();
                if(curr == endWord) return steps;
                for(int i = 0; i < curr.length(); ++i){
                    for(char c = 'a'; c <= 'z'; ++c){
                        char temp = curr[i];
                        curr[i] = c;
                        if(exist.count(curr)){ 
                            dfs.push(curr);
                            exist.erase(curr);
                        }
                        curr[i] = temp;
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
