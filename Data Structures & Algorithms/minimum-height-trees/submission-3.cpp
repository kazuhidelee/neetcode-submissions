class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        unordered_map<int, vector<int>> trees;
        vector<int> degrees(n, 0);
        for(vector<int> e: edges){
            trees[e[0]].push_back(e[1]);
            degrees[e[0]]++;
            trees[e[1]].push_back(e[0]);
            degrees[e[1]]++;
        }
        queue<int> bfs;
        for(int i = 0; i < n; ++i){
            if(degrees[i] == 1){
                bfs.push(i);
            }
        }
        int left = n;
        while(left > 2){
            int size = bfs.size();
            left -= size;
            for(int i = 0; i < size; ++i){
                int curr = bfs.front();
                bfs.pop();
                for(int e: trees[curr]){
                    degrees[e]--;
                    if(degrees[e] == 1){
                        bfs.push(e);
                    }
                }
            }
        }
        vector<int> res;
        while(!bfs.empty()){
            res.push_back(bfs.front());
            bfs.pop();
        }
        return res;
    }
};