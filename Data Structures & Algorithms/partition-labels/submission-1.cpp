class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i = 0; i < s.length(); ++i){
            last[s[i]] = i;
        }
        vector<int> res;
        int boundary = 0;
        int count = 0;
        for(int i = 0; i < s.length(); ++i){
            count++;
            boundary = max(boundary, last[s[i]]);
            if(i == boundary){
                res.push_back(count);
                count = 0;
            }
        }
        return res;
    }
};
