class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int r = 0;
        int res = 0;
        int max_freq = 0;
        while(r < s.length()){
            freq[s[r]]++;
            max_freq = max(max_freq, freq[s[r]]);
            int curr_window_size = r - l + 1;
            if(curr_window_size - max_freq > k)
            {
                freq[s[l]]--;
                ++l;
            }
            res = max(res, r - l + 1);
            ++r;
        }
        return res;
    }
};