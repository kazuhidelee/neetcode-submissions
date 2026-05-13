class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

    void backtrack(string s, int index, vector<string> &curr, vector<vector<string>> &res){
        if(index == s.length()){
            res.push_back(curr);
            return;
        }
        for(int i = index; i < s.length(); ++i){
            if(i - index + 1 == 1 || isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                backtrack(s, i + 1, curr, res);
                curr.pop_back();
            }
            // curr_str.pop_back();
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};
