class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mapping;
        for(vector<int> prereq: prerequisites){
            mapping[prereq[1]].push_back(prereq[0]);
        }
        vector<bool> res;
        for(vector<int> q: queries){
            int dest = q[0];
            int start = q[1];
            vector<bool> visited(numCourses, false);
            queue<int> bfs;
            bfs.push(start);
            visited[start] = true;
            bool found = false;
            while(!bfs.empty()){
                int curr = bfs.front();
                bfs.pop();
                if(curr == dest){
                    res.push_back(true);
                    found = true;
                    break;
                }
                for(int prereq: mapping[curr]){
                    if(!visited[prereq]){
                        bfs.push(prereq);
                        visited[prereq] = true;
                    }
                }
            }
            if(!found){
                res.push_back(false);
            }
        }
        return res;
    }
};