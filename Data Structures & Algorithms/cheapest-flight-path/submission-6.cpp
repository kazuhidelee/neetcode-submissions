class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        for(int i = 0; i < k + 1; ++i){
            vector<int> copy = distance;
            for(vector<int> f: flights){
                int new_src = f[0];
                int new_dst = f[1];
                int new_cost = f[2];
                if(distance[new_src] != INT_MAX){
                    copy[new_dst] = min(new_cost + distance[new_src], copy[new_dst]);
                }
            }
            distance = copy;
        }
        if(distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};
