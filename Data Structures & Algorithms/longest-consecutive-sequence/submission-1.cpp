class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        int res = 0;
        for(int i: s){
            int l = 0;
            if(s.find(i - 1) == s.end()){
                ++l;
                while(s.find(i + l) != s.end()){
                    ++l;
                }
                res = max(res, l);
            }
        }
        return res;
    }
};
