class Solution {
public:
    string find_freq(string str){
        vector<int> freq(26, 0);
        for(char c: str){
            freq[c - 'a']++;
        }
        string res = "";
        for(int i: freq){
            res += (char)i;
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string str: strs){
            string freq = find_freq(str);
            groups[freq].push_back(str);
        }
        vector<vector<string>> res;
        for(auto group: groups){
            res.push_back(group.second);
        }
        return res;
    }
};
