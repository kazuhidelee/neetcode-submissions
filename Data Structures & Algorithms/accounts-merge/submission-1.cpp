class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        // email to name
        unordered_map<string, string> email_owner;
        for(vector<string> account: accounts){
            string name = account[0];
            string prev = account[1];
            email_owner[prev] = name;
            for(int i = 2; i < account.size(); ++i){
                graph[prev].push_back(account[i]);
                graph[account[i]].push_back(prev);
            }
        }
        for(auto &[email, neighbors]: graph){
            cout << email << ": ";
            for(auto n: neighbors){
                cout << n << ", ";
            }
            cout << "\n";
        }
        vector<vector<string>> res;
        unordered_set<string>visited;
        for(vector<string> account: accounts){
            string email = account[1];
            if(!visited.count(email)){
                vector<string> curr;
                curr.push_back(email_owner[email]);
                queue<string> bfs;
                bfs.push(email);
                visited.insert(email);
                while(!bfs.empty()){
                    string curr_email = bfs.front();
                    bfs.pop();
                    curr.push_back(curr_email);
                    for(string neighbors: graph[curr_email]){
                        if(!visited.count(neighbors)){
                            visited.insert(neighbors);
                            bfs.push(neighbors);
                        }
                    }
                }
                res.push_back(curr);
            }
        }
        return res;
    }
};