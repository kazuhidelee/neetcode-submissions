class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int res = 0;
        int l = 0;
        for(int r = 0; r < s.length(); ++r){
            while(seen.count(s[r])){
                seen.erase(s[l]);
                ++l;
            }
            seen.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};