class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mapping;
        vector<int> in_degree(numCourses, 0);
        for(vector<int> prereq: prerequisites){
            mapping[prereq[0]].push_back(prereq[1]);
            in_degree[prereq[1]]++;
        }
        vector<bool> res;
        queue<int> bfs;
        for(int i = 0; i < numCourses; ++i){
            if(in_degree[i] == 0){
                bfs.push(i);
            }
        }
        vector<unordered_set<int>> reachable(numCourses);
        while(!bfs.empty()){
            int curr_node = bfs.front();
            bfs.pop();
            for(int &neighbors: mapping[curr_node]){
                reachable[neighbors].insert(curr_node);
                for(int c: reachable[curr_node]){
                    reachable[neighbors].insert(c);
                }
                in_degree[neighbors]--;
                if(in_degree[neighbors] == 0){
                    bfs.push(neighbors);
                }
                
            }
        }
        for(vector<int> &q: queries){
            int prereq = q[0];
            int course = q[1];
            res.push_back(reachable[course].count(prereq));
        }
        return res;
    }
};