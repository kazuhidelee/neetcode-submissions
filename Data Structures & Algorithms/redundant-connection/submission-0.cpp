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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1, 0);
        for(int i = 1; i < edges.size(); ++i){
            parents[i] = i;
        }
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            if(!UnionFind(u, v, parents)){
                return e;
            }
        }
        return {};
    }
};
