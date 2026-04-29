class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> coords;
        for(int i = 0; i < position.size(); ++i){
            coords.push_back({position[i], speed[i]});
        }
        sort(coords.rbegin(), coords.rend());
        double current = -1;
        int num = 0;
        for(auto p: coords){
            double pos = p.first;
            double spd = p.second;
            double time = (target - pos) / spd;
            if(time > current){
                current = time;
                ++num;
            }
        }
        return num;
    }
};
