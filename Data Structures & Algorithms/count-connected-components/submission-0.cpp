class Solution {
public:
    int find(int target, vector<int> &parents){
        if(parents[target] != target){
            parents[target] = find(parents[target], parents);
        }
        return parents[target];
    }

    bool UnionFind(int u, int v, vector<int> &parents){
        int pu = find(u, parents);
        int pv = find(v, parents);
        if(pu == pv){
            return false;
        }
        parents[pu] = pv;
        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, 0);
        for(int i = 0; i < n; ++i){
            parents[i] = i;
        }
        unordered_set<int> components;
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            UnionFind(u, v, parents);
        }
        for(int i = 0; i < n; ++i){
            components.insert(find(i, parents));
        }
        return components.size();
    }
};
