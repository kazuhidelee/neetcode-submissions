class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int start = 0;
        int res = 0;
        int end = 0;
        while(end < s.length()){
            if(seen.find(s[end]) == seen.end()){
                seen.insert(s[end]);
                res = max(res, end - start + 1);
                ++end;
            }else{
                seen.erase(s[start]);
                ++start;
            }
        }
        return res;
    }
};
