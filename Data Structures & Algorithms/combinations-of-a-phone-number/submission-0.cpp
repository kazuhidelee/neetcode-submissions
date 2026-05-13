class Solution {
public:
    void backtrack(string digits, unordered_map<char, string> &mapping, string &curr, int index, vector<string> &res){
        if(curr.length() == digits.length()){
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < mapping[digits[index]].length(); ++i){
            curr += mapping[digits[index]][i];
            backtrack(digits, mapping, curr, index + 1, res);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping = {{'2', "abc"}, {'3', "edf"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},};
        vector<string> res;
        string curr = "";
        if(digits.length() == 0) return res;
        backtrack(digits, mapping, curr, 0, res);
        return res;
    }
};
