class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s: strs){
            res += to_string(s.length());
            res += "/";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr = "";
        int i = 0;
        while(i < s.length()){
            string l = "";
            while(s[i] != '/'){
                l += s[i];
                ++i;
            }
            int length = stoi(l);
            ++i;
            cout << length << endl;
            string temp = s.substr(i, length);
            res.push_back(temp);
            i += length;
            l = "";
        }
        return res;
    }
};
