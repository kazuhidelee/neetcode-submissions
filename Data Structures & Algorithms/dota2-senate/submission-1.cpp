class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> d;
        queue<int> r; 
        int r_skip = 0;
        int d_skip = 0;
        for(int i = 0; i < senate.size(); ++i){
            char c = senate[i];
            if(c == 'R'){
                r.push(i);
            }else{
                d.push(i);
            }
        }

        while(!d.empty() && !r.empty()){
            if(d.front() < r.front()){
                d.push(d.front() + senate.size());
            }else{
               r.push(r.front() + senate.size());
            }
            d.pop();
            r.pop();
        }

        if(d.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};