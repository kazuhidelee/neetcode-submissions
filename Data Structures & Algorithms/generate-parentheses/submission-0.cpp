class Solution {
public:
    void bfs(vector<string>&res, string curr, int n, int open, int close){
        if(curr.length() == 2 * n){
            res.push_back(curr);
            return;
        }

        if(open > close){
            curr += ')';
            bfs(res, curr, n, open, close + 1);
            curr.pop_back();
        }
        if(open < n){
            curr += '(';
            bfs(res, curr, n, open + 1, close);
            curr.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bfs(res, "", n, 0, 0);
        return res;
    }
};
