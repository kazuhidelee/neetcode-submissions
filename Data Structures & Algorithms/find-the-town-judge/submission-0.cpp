class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> mapping;
        vector<int> in_degree(n + 1, 0);
        for(vector<int> t: trust){
            mapping[t[0]].push_back(t[1]);
            in_degree[t[1]]++;
        }
        for(int i = 1; i <= n; ++i){
            if(in_degree[i] == n - 1 && !mapping.count(i)) return i;
        }
        return -1;
    }
};