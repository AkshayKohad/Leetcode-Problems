class Solution {
public:
    
    struct mycmp{
      
        bool operator()(pair<int,string>f,pair<int,string>s)
        {
            if(f.first==s.first)
                return f.second>s.second;
            
            return f.first<s.first;
        }
        
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,mycmp>pq;
        
        map<string,int>mp;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        for(auto k:mp)
        {
            
            pq.push({k.second,k.first});
        }
        
        vector<string>res;
        while(pq.size()>0 && k--)
        {
            string s = pq.top().second;
         //   cout<<pq.top().second<<" "<<pq.top().first<<endl;
            res.push_back(s);
            
            pq.pop();
        }
        
        return res;
    }
};
