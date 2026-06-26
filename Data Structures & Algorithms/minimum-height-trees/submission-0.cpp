class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> trees;
        for(vector<int> e: edges){
            trees[e[0]].push_back(e[1]);
            trees[e[1]].push_back(e[0]);
        }
        vector<int> heights(n, 0);
        int min_h = INT_MAX;
        for(int i = 0; i < n; ++i){
            queue<int> bfs;
            unordered_set<int> visited;
            bfs.push(i);
            visited.insert(i);
            int height = 0;
            while(!bfs.empty()){
                int s = bfs.size();
                for(int j = 0; j < s; ++j){
                    int curr = bfs.front();
                    bfs.pop();
                    for(int e: trees[curr]){
                        if(!visited.count(e)){
                            bfs.push(e);
                            visited.insert(e);
                        }
                    }
                }
                height++;
            }
            heights[i] = height - 1;
            min_h = min(heights[i], min_h);
            cout << heights[i] << endl;
        }

        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(heights[i] == min_h) res.push_back(i);
        }
        return res;
    }
};