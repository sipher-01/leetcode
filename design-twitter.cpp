class Twitter {
public:
    unordered_map<int,set<int>>user_friends;
    priority_queue<vector<int>>time;
    int cur;
    Twitter() {
        cur = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time.push({cur++,tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int n = 0;
        priority_queue<vector<int>> temp = time;
        while(!temp.empty() && n<10){
            auto t = temp.top();
            temp.pop();
            if(t[2]==userId || user_friends[userId].count(t[2])){
                ans.push_back(t[1]);
                n++;
            }
        }
            return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        user_friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_friends[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */