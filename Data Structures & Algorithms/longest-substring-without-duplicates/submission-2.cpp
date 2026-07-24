class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int res = 0;
        int l = 0;
        for(int r = 0; r < s.length(); ++r){
            if(seen.count(s[r])){
                l = max(seen[s[r]] + 1, l);
            }
            seen[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};