class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
           int s = digits[i] + carry;
           int digit = s % 10;
           carry = s / 10;
           res.push_back(digit);
        }
        if(carry > 0){
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
      
    }
};
