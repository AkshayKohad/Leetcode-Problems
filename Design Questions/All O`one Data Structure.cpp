class AllOne {
public:
    
    map<string,int>mp;
    
    map<int,set<string>>s;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(mp.find(key)==mp.end())
        {
            mp[key] = 1;
            s[1].insert(key);
        }
        
        else{
            int count = mp[key];
            
            s[count].erase(key);
            
            if(s[count].size()==0)
                s.erase(count);
            
            s[(count+1)].insert(key);
            
            mp[key] = count+1;
        }
    }
    
    void dec(string key) {
        
        
        int count = mp[key];
        
        s[count].erase(key);
        
         if(s[count].size()==0)
                s.erase(count);
        
        if(count-1>0)
        {
            s[count-1].insert(key);
            
            mp[key] = count-1;
        }
        
        else{
            mp.erase(key);
        }
        
        
    }
    
    string getMaxKey() {
        
        if(mp.size()==0)
            return "";
        
        string res = *(s[s.rbegin()->first].begin());
        return res;
    }
    
    string getMinKey() {
        if(mp.size()==0)
            return "";
        
        string res = *(s[s.begin()->first].begin());
        return res;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
