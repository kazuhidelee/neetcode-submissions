class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> freq;
        for(int h: hand){
            freq[h]++;
        }
        sort(hand.begin(), hand.end());
        for(int i: hand){
            if(freq[i] == 0) continue;
            for(int start = i; start < i + groupSize; ++start){
                if(freq.count(start)){
                    freq[start]--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
