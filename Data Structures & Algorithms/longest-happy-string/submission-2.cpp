class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // count, char
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string res = "";
        while (!pq.empty()){
           auto curr = pq.top();
           pq.pop();
           if(res.length() > 1 && res[res.length() - 1] == curr.second && res[res.length() - 2] == curr.second){
            if(pq.empty()) break;
            auto sec = pq.top();
            pq.pop();
            res += sec.second;
            sec.first--;
            pq.push(curr);
            if(sec.first > 0) pq.push(sec);
           }else{
            res += curr.second;
            curr.first--;
            if(curr.first > 0) pq.push(curr);
           }
        }
        return res;
    }
};