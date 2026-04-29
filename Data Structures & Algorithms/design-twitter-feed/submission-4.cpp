class Twitter {
private:
    vector<vector<bool>> following = vector<vector<bool>>(101, vector<bool>(101, false));
    // postid, userid
    int time = 0;
    priority_queue<vector<int>> tweets;
public:
    Twitter() {
        for(int i = 0; i < 101; ++i){
            following[i][i] = true;
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push({time, tweetId, userId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<vector<int>> leftovers;
        vector<int> res;
        while(!tweets.empty() && res.size() < 10){
            auto curr = tweets.top();
            tweets.pop();
            if(following[userId][curr[2]]){
                res.push_back(curr[1]);
            }
            leftovers.push_back(curr);

        }
        for(auto l: leftovers){
            tweets.push(l);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId][followeeId] = false;
        }
    }
};
