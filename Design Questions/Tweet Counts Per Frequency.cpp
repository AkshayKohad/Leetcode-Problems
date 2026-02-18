class TweetCounts {
public:
    map<string,multiset<int>>mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = 0;
        if(freq=="minute"){
            interval = 60;
        }else if(freq=="hour"){
            interval = 3600;
        }else{
            interval = 86400;
        }

        vector<int>res;
        auto &st = mp[tweetName];
        int cur_start = startTime;
        while(cur_start<=endTime){
            int cur_end = min(cur_start + interval - 1, endTime);

            auto s = st.lower_bound(cur_start);
            auto e = st.upper_bound(cur_end);

            if (s == st.end() || s == e) {
                res.push_back(0);
            } else {
                res.push_back(distance(s, e));
            }

            cur_start += interval;
        }

        return res; 
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
