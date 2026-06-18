class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> encoded;
        stack<int> nums;
        string curr = "";
        string n = "";
        for(char c: s){
            if(isdigit(c)){
                n += c;
            }else if(c == '['){
                nums.push(stoi(n));
                encoded.push(curr);
                curr = "";
                n = "";
            }else if(c == ']'){
                string temp = "";
                int n = nums.top();
                while(n--) temp += curr;
                nums.pop();
                if(!encoded.empty()){
                    string t = encoded.top();
                    temp = t + temp;
                    encoded.pop();
                }

                curr = temp;
            }else{
                // normal letter
                curr += c;
            }
        }
        return curr;
    
    }
};