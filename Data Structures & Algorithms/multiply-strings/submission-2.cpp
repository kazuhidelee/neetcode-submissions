class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> sums;
        for(int i = num1.size() - 1; i >= 0; --i){
            string curr = "";
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; --j){
                int product = (num1[i] - '0') * (num2[j] - '0') + carry;
                int digit = product % 10;
                carry = product / 10;
                curr = char('0' + digit) + curr;
            }
            if(carry > 0) curr = char('0' + carry) + curr;
            int num_padding = num1.size() - 1 - i;
            for(int p = 0; p < num_padding; ++p){
                curr += '0';
            }
            sums.push_back(curr);
        }
        string prev = "0";
        for(int i = 0; i < sums.size(); ++i){
            string curr = sums[i];
            string res = "";
            int carry = 0;
            int j = curr.length() - 1;
            int k = prev.length() - 1;
            while(carry > 0 || j >= 0 || k >= 0){
                int total = carry;
                if(j >= 0){
                    total += (curr[j] - '0');
                    --j;
                }
                if(k >= 0){
                    total += (prev[k] - '0');
                    --k;
                }
                int digit = total % 10;
                res = char('0' + digit) + res;
                carry = total / 10;
            }
            prev = res;
        }
        if(prev[0] == '0') return "0";
        return prev;
    }
};
