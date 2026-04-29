class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;

        vector<int> freq1(26, 0);
        for (char c : s1) freq1[c - 'a']++;

        vector<int> freq2(26, 0);
        for (int j = 0; j < s1.length(); ++j) {
            freq2[s2[j] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq1[i] == freq2[i]) matches++;
        }

        int start = 0;
        for (int end = s1.length(); end < s2.length(); ++end) {
            if (matches == 26) return true;

            // Add new character
            int inChar = s2[end] - 'a';
            freq2[inChar]++;
            if (freq2[inChar] == freq1[inChar]) {
                matches++;
            } else if (freq2[inChar] - 1 == freq1[inChar]) {
                matches--;
            }

            // Remove old character
            int outChar = s2[start] - 'a';
            freq2[outChar]--;
            if (freq2[outChar] == freq1[outChar]) {
                matches++;
            } else if (freq2[outChar] + 1 == freq1[outChar]) {
                matches--;
            }

            start++;
        }

        return matches == 26;
    }
};
