class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> pre_req;
        unordered_map<int, int> in_degree;
        for(auto pre: prerequisites){
            pre_req[pre[1]].insert(pre[0]);
            in_degree[pre[0]]++;
        }
        vector<int> res;
        int completed = 0;
        queue<int> bfs;
        for(int i = 0; i < numCourses; ++i){
            if(in_degree[i] == 0){
                bfs.push(i);
                // visited.insert(i);
            }
        }
        while(!bfs.empty()){
            int curr = bfs.front();
            bfs.pop();
            res.push_back(curr);
            completed++;
            
            for(int i: pre_req[curr]){
                in_degree[i]--;
                if(in_degree[i] == 0){
                    bfs.push(i);
                }
            }
        }
        if(completed == numCourses){
            return res;
        }else{
            return {};
        }

    }
};
