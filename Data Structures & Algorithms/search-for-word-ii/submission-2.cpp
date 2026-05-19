class Solution {
public:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool complete = false;
        TrieNode(){
            complete = false;
        }
    };

    void insert(string word, TrieNode* head) {
        TrieNode* ptr = head;
        for(char c: word){
            if(!ptr->children.count(c)){
                ptr->children[c] = new TrieNode();
            }
            ptr = ptr->children[c];
        }
        ptr->complete = true;
    }

    void dfs(vector<vector<char>>& board, vector<string> &res, string &curr, unordered_set<int> &visited, TrieNode* head,
    int r, int c){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;
        if(visited.count(r * board[0].size() + c)) return;
        if(!head->children.count(board[r][c])) return;
        curr += board[r][c];
        head = head->children[board[r][c]];
        if(head->complete){
            res.push_back(curr);
            head->complete = false;
        }
        visited.insert(r * board[0].size() + c);
        dfs(board, res, curr, visited, head, r - 1, c);
        dfs(board, res, curr, visited, head, r + 1, c);
        dfs(board, res, curr, visited, head, r, c - 1);
        dfs(board, res, curr, visited, head, r, c + 1);
        visited.erase(r * board[0].size() + c);
        curr.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        unordered_set<int> visited;
        string curr = "";
        TrieNode* head = new TrieNode();
        for(string w: words){
            insert(w, head);
        }
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(board, res, curr, visited, head, r, c);
            }
        }
        return res;
    }
};
