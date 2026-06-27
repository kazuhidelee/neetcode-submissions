class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> check;
        for(string d: deadends){
            if(d == "0000") return -1;
            check.insert(d);
        }
        queue<string> bfs;
        unordered_set<string> visited;
        bfs.push("0000");
        visited.insert("0000");
        int res = INT_MAX; 
        int turns = 0;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i = 0; i < size; ++i){
                string curr = bfs.front();
                bfs.pop();
                if(curr == target) return turns;
                for(int i = 0; i < 4; ++i){
                    char c;
                    if(curr[i] == '9'){
                        c = '0';
                    }else{
                        c = curr[i] + 1;
                    }
                    string temp1 = curr.substr(0, i) + c + curr.substr(i + 1);
                    if(curr[i] == '0'){
                        c = '9';
                    }else{
                        c = curr[i] - 1;
                    }
                    string temp2 = curr.substr(0, i) + c + curr.substr(i + 1);
                    if(!visited.count(temp1) && !check.count(temp1)){
                        bfs.push(temp1);
                        visited.insert(temp1);
                    } 
                    if(!visited.count(temp2) && !check.count(temp2)){
                        bfs.push(temp2);
                        visited.insert(temp2);
                    } 

                }
            }
            turns++;
        }
        return -1;
    }
};