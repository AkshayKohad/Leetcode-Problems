class AuthenticationManager {
public:
    set<pair<int,string>>time_token;
    map<string,int>token_time;
    multiset<int>time_record;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if(token_time.find(tokenId)!=token_time.end())return;

        token_time[tokenId] = currentTime + ttl;
        time_token.insert({currentTime + ttl, tokenId});
        time_record.insert(currentTime + ttl);
    }
    
    void renew(string tokenId, int currentTime) {
        if(token_time.find(tokenId) == token_time.end()) return;
        int cur_time = token_time[tokenId];

        if(cur_time <= currentTime)return;

        time_token.erase({cur_time,tokenId});
        token_time[tokenId] = currentTime + ttl;
        time_token.insert({currentTime + ttl,tokenId});
        time_record.erase(time_record.find(cur_time));
        time_record.insert(currentTime + ttl);
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto it = time_record.lower_bound(currentTime+1);
        int result = distance(it,time_record.end());

        return result;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
