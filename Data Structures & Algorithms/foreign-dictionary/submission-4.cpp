class Solution {
public:
    bool compare(string s1, string s2, unordered_map<char, unordered_set<char>> &graph, unordered_map<char, int> &in_degree){
        int n = min(s1.length(), s2.length());
        for(int i = 0; i < n; ++i){
            if(s1[i] != s2[i]){
                if(graph[s1[i]].count(s2[i])) return true;
                graph[s1[i]].insert(s2[i]);
                in_degree[s2[i]]++;
                return true;
            }
        }
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_set<char> chars;
        unordered_map<char, int> in_degree;
        int n = words.size();
        string prev = words[0];
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < words[i].length(); ++j){
                chars.insert(words[i][j]);
            }
        }
        // constructing connections of nodes, and in degree
        for(int i = 1; i < words.size(); ++i){
            if(!compare(prev, words[i], graph, in_degree) && prev.length() > words[i].length()) return "";
            prev = words[i];
        }
        queue<char> bfs;
        for(char c: chars){
            if(in_degree[c] == 0){
                bfs.push(c);
            }
        }
        string res = "";
        while(!bfs.empty()){
            char curr = bfs.front();
            bfs.pop();
            res += curr;
            for(char c: graph[curr]){
                in_degree[c]--;
                if(in_degree[c] == 0){
                    bfs.push(c);
                }
            }
        }
        if(res.length() != chars.size()) return "";
        return res;
        
    }
};
