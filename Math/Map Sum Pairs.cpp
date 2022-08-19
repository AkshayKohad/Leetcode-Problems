class MapSum {
public:
    
    class trie{
      
        public:
        
         trie*characters[26];
        bool isEnd;
        
        
        trie()
        {
            for(int i=0;i<26;i++)
                characters[i] = NULL;
            isEnd = false;
        }
    };
    
    trie*root;
        
        unordered_map<string,int>store;
        

    MapSum() {
        
        root = new trie();                
    }
    
    void search_count(trie*cur,int &count,string ans)
    {
        if(cur->isEnd==true) 
        {
            count += store[ans];
        }
        
        for(int i=0;i<26;i++)
        {
            if(cur->characters[i]==NULL) continue;
            
            ans.push_back('a' + i);
            search_count(cur->characters[i],count,ans);
            ans.pop_back();
        }
    }
    
    void insert(string key, int val) {
        
        if(store.find(key)!=store.end())
        {
            store[key] = val;
            return;
        }
        
        trie *p = root;
        
        
        for(int i=0;i<key.length();i++)
        {
            int k = key[i]-'a';
            if(p->characters[k]==NULL)
            {
                p->characters[k] = new trie();
            }
            
            p = p->characters[k];
        }
        
        p->isEnd = true;
        
        
        store[key] = val;
        
        return;
    }
    
    int sum(string prefix) {
        trie*p = root;
        
        for(int i=0;i<prefix.length();i++)
        {
            int k = prefix[i]-'a';
            
            if(p->characters[k]==NULL)
                return 0;
            
            p = p->characters[k];
        }
        int count = 0;
        string ans = prefix;
        search_count(p,count,ans);
        
        return count;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
