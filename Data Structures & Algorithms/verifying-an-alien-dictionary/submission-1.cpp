class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int counter = 0;
        unordered_map<char, int> ordering;
        for(char c: order){
            ordering[c] = counter;
            counter++;
        }

        for(int i = 1; i < words.size(); ++i){
            string w1 = words[i - 1];
            string w2 = words[i];
            int ptr = 0;
            while(ptr < min(w1.length(), w2.length()) && w1[ptr]== w2[ptr]){
                ++ptr;
            }
            if(ptr >= w1.length() || ptr >= w2.length()){
                if(w1.length() > w2.length()) return false;
            }else if(ordering[w1[ptr]] > ordering[w2[ptr]]) return false;

        }
        return true;
    }
};