class Solution {
public:
    // bool contains(unordered_map<char, int> &in_t, unordered_map<char, int> &in_s){
    //     for(auto c: in_t){
    //         if(in_s[c.first] < c.second){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char, int> in_t;
        unordered_map<char, int> in_s;
        for(char i: t){
            in_t[i]++;
        }
        int l = 0;
        string res = "";
        int curr_length = INT_MAX;
        int need = t.length();
        for(int r = 0; r < s.length(); ++r){
            in_s[s[r]]++;
            if(in_s[s[r]] <= in_t[s[r]]) need--;
            while(need == 0){
                if(curr_length > r - l + 1){
                    res = s.substr(l, r - l + 1);
                    curr_length = r - l + 1;
                }
                in_s[s[l]]--;
                if(in_s[s[l]] < in_t[s[l]]) need++;
                ++l;
            }
        }
        return res;

    }
};
