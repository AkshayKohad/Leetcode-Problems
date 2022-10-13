class RandomizedCollection {
public:
    
    vector<int>v;
    unordered_map<int,int>mp;
    
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = false;
        
        if(mp[val]==0)
        {
            flag = true;
            mp[val]++;
            v.push_back(val);
        }
        
        else{
            mp[val]++;
            v.push_back(val);
        }
        
        return flag;
        
    }
    
    bool remove(int val) {
        
        bool flag = false;
        
        if(mp[val]>0)
        {
            flag = true;
            
            mp[val]--;
            
            auto it = find(v.begin(),v.end(),val);
            
            v.erase(it);
        }
        
        return flag;
        
    }
    
    int getRandom() {
        
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
