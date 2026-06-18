class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        string curr_file = "/";
        stack<string> files;
        for(int i = 0; i < path.length(); ++i){
            char c = path[i];
            if(c != '/'){
                curr_file += c;
            }else{
                if(curr_file == "/.."){
                    if(!files.empty()) files.pop();   
                }else if(curr_file != "/" && curr_file != "/."){
                    files.push(curr_file);
                }   
                curr_file = "/";
            }
        }
        if(curr_file == "/.."){
            if(!files.empty()) files.pop();   
        }else if(curr_file != "/" && curr_file != "/."){
            files.push(curr_file);
        }

        while(!files.empty()){
            res = files.top() + res;
            files.pop();
        }

        if(res == "") return "/";
        return res;
    }
};