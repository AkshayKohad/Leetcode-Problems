class Twitter {
public:
    vector<int>recent_tweets;
    
    //tweet - userid
    map<int,int>tweet_record;
    
    // userid-userid
    
    // folowers record
    
    map<int,set<int>>followers;
    
    // userid-userid
    
    // following record
    map<int,set<int>>following;
    
    
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        recent_tweets.push_back(tweetId);
        tweet_record[tweetId] = userId;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>recent;
        
        int count = 0;
        
        int j = recent_tweets.size()-1;
        
        while(j>=0)
        {
            int tweet = recent_tweets[j];
            
            int user = tweet_record[tweet];
            
            if(user == userId || following[userId].find(user)!=following[userId].end())
            {
                recent.push_back(tweet);
                
                if(recent.size()==10)
                break;
            }
            
            
            
            j--;
        }
        
        return recent;
        
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        followers[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        followers[followeeId].erase(followerId);
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
