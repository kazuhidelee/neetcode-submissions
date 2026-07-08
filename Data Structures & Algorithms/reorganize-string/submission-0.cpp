class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        for(char c: s){
            counts[c]++;
        }
        string res = "";
        
        priority_queue<pair<int, char>> pq;
        for(auto c: counts){
            pq.push({c.second, c.first});
        }
        while(pq.size() >= 2){
           auto fir = pq.top();
           pq.pop();
           auto sec = pq.top();
           pq.pop();
           res += fir.second;
           res += sec.second;
           fir.first--;
           sec.first--;
           if(fir.first > 0){
                pq.push(fir);
           }
           if(sec.first > 0){
                pq.push(sec);
           }
        }
        if(!pq.empty()){
            if(pq.top().first == 1){
                res += pq.top().second;
                pq.pop();
            }else{
                return "";
            }
        } 
        return res;

    }
};