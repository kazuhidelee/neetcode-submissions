class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length() - 1;
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
        string curr_str = "";
        for(int i = index; i < s.length(); ++i){
            curr_str += s[i];
            if(curr_str.length() == 1 || isPalindrome(curr_str)){
                curr.push_back(curr_str);
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
