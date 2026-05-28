class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            in_degree[course]++;
        }
        queue<int> bfs;
        for(int i = 0; i < numCourses; ++i){
            if(in_degree[i] == 0){
                bfs.push(i);
            }
        }
        vector<int> res;
        int course_taken = 0;
        while(!bfs.empty()){
            int curr = bfs.front();
            bfs.pop();
            res.push_back(curr);
            course_taken++;
            for(int courses: adj[curr]){
                in_degree[courses]--;
                if(in_degree[courses] == 0){
                    bfs.push(courses);
                }
            }
        }
        if(course_taken == numCourses){
            return res;
        }
        return {};
    }
};
