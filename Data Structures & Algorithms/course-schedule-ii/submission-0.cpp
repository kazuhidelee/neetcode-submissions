class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> pre_req;
        unordered_set<int> visited;
        for(auto pre: prerequisites){
            pre_req[pre[0]].insert(pre[1]);
        }
        vector<int> res;
        int completed = 0;
        queue<int> bfs;
        for(int i = 0; i < numCourses; ++i){
            if(pre_req[i].size() == 0){
                bfs.push(i);
                visited.insert(i);
            }
        }
        while(!bfs.empty()){
            int curr = bfs.front();
            bfs.pop();
            // if(visited.count(curr)) return {};
            res.push_back(curr);
            completed++;
            for(int i = 0; i < numCourses; ++i){
                pre_req[i].erase(curr);
                if(!visited.count(i) && pre_req[i].size() == 0){
                    cout << "here" << endl;
                    bfs.push(i);
                    visited.insert(i);
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
