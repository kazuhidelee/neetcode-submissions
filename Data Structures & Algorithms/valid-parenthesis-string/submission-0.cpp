class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            if(c == '('){
                open.push(i);
            }else if(c == ')'){
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }else{
                star.push(i);
            }
        }
        while(!star.empty() && !open.empty()){
            int star_pos = star.top();
            int open_pos = open.top();
            if(star_pos > open_pos){
                open.pop();
                star.pop();
            }else{
                break;
            }
        }

        return open.empty();
    }
};
