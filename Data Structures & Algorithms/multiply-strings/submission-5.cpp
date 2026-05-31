class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> v1;
        vector<int> v2;
        for(int i = num1.length() - 1; i >=0 ; --i){
            v1.push_back(num1[i] - '0');
        }
        for(int i = num2.length()- 1; i >=0 ; --i){
            v2.push_back(num2[i] - '0');
        }
        vector<int> summing(num1.length() + num2.length(), 0);
        for(int i = 0; i < v2.size(); ++i){
            for(int j = 0; j < v1.size(); ++j){
                int product = v1[j] * v2[i];
                summing[i + j] += product;
                summing[i + j + 1] += summing[i + j] / 10;
                summing[i + j] %= 10;
            }
        }
        string res = "";
        for(int i = summing.size() - 1; i >= 0; --i){
            if(res == "" && summing[i] == 0){
                continue;
            }else{
                res += char('0' + summing[i]);
            }
        }
        if(res == "") return "0";
        return res;
     
    }
};
