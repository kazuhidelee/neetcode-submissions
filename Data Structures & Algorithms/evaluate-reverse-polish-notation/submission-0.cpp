class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token: tokens){
            if(token == "+"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop(); 
                s.push(num1 + num2);
            }else if(token == "-"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 - num1);
            }else if(token == "*"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 * num1);
            }else if(token == "/"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 / num1);
            }else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
