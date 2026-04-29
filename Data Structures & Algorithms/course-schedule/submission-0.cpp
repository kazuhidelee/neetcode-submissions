class Solution {
public:
    bool bfs(int i, unordered_map<int, vector<int>> &adj, unordered_set<int> &s){
        // course has no prereq
        if(adj[i].empty()){
            return true;
        }
        // if there is a cycle
        if(s.find(i) != s.end()){
            return false;
        }
        s.insert(i);
        // check all its pre reqs
        for(int c: adj[i]){
            if(!bfs(c, adj, s)){
                return false;
            }
        }
        s.erase(i);
        adj[i] = {};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < numCourses; ++i){
            adj[i] = {};
        }
        for(auto preq: prerequisites){
            adj[preq[0]].push_back(preq[1]);
        }
        unordered_set<int> s;
        for(int i = 0; i < numCourses; ++i){
            if(!bfs(i, adj, s)){
                return false;
            }
        }
        return true;

    }
};
