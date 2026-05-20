class Solution {
public:
    void dfs(unordered_map<string, vector<string>> &adj, vector<string> &res, string curr){
        while(adj[curr].size() > 0){
            string airport = adj[curr].back();
            adj[curr].pop_back();
            dfs(adj, res, airport);
        }
        res.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(vector<string> ticket: tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto &a: adj){
            sort(a.second.rbegin(), a.second.rend());
        }
        vector<string> res;  
        string curr = "JFK";
        dfs(adj, res, curr);
        reverse(res.begin(), res.end());
        return res;
    }
};
