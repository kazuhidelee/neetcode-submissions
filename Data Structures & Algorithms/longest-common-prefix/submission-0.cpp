class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prev = strs[0];
        for(int i = i; i < strs.size(); ++i){
            string curr = strs[i];
            string longest = "";
            int min_len = min(prev.length(), curr.length());
            for(int j = 0; j < min_len; ++j){
                if(prev[j] == curr[j]){
                    longest += prev[j];
                }else{
                    break;
                }
            }
            prev = longest;
        }
        return prev;
    }
};