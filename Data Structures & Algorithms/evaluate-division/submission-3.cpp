class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> edges;
        int ptr = 0;
        for(auto e: equations){
            string x = e[0];
            string y = e[1];
            edges[x][y] = values[ptr];
            edges[y][x] = 1.0 / values[ptr];
            ++ptr;
        }
        vector<double> res;
        for(auto q: queries){
            string x = q[0];
            string y = q[1];
            if(!edges.count(x)){
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> bfs;
            unordered_set<string> visited;
            bfs.push({x, 1});
            visited.insert(x);
            bool valid = false;
            while(!bfs.empty()){
                string curr = bfs.front().first;
                cout << curr << " ";
                double weight = bfs.front().second;
                bfs.pop();
                if(curr == y){
                    res.push_back(weight);
                    valid = true;
                    break;
                }
                for(auto &[node, w]: edges[curr]){
                    if(!visited.count(node)){
                        visited.insert(node);
                        bfs.push({node, w * weight});
                    }
                }
            }
            cout  << " \n";
            if(!valid){
                res.push_back(-1);
            }
        }
        return res;
    }
};