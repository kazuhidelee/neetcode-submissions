class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mapping;
        for(vector<int> prereq: prerequisites){
            mapping[prereq[1]].push_back(prereq[0]);
        }
        vector<bool> res;
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for(int i = 0; i < numCourses; ++i){
            vector<bool> visited(numCourses, false);
            queue<int> bfs;
            int start = i;
            bfs.push(i);
            visited[i] = true;
            while(!bfs.empty()){
                int curr = bfs.front();
                bfs.pop();
                for(int prereq: mapping[curr]){
                    if(!visited[prereq]){
                        bfs.push(prereq);
                        reachable[start][prereq] = true;
                        visited[prereq] = true;
                    }
                }
            }
        }
        for(vector<int> &q: queries){
            int dest = q[0];
            int start = q[1];
            res.push_back(reachable[start][dest]);
        }
        return res;
    }
};