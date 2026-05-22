class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = INT_MIN;
        string max_p;
        for(int i = 0; i < s.length(); ++i){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                --l;
                ++r;
            }
            if(max_len < r - l - 1){
                max_len = r - l - 1;
                max_p = s.substr(l + 1, r - l - 1);

            }
            l = i;
            r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                --l;
                ++r;
            }
            if(max_len < r - l - 1){
                max_len = r - l - 1;
                max_p = s.substr(l + 1, r - l - 1);

            }
        }
        return max_p;
    }
};
