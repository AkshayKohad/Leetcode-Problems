class Solution {
public:

    struct mycmp{
      
        bool operator()(pair<int,string>f,pair<int,string>s)
        {
            if(f.first==s.first)
                return f.second<s.second;
            
            return f.first>s.first;
        }
        
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        priority_queue<pair<int,string>,vector<pair<int,string>>,mycmp>pq;
        map<string,int>mp;
        for(auto word : words){
            mp[word]++;
        }

        for(auto m : mp){
            if(pq.size()<k){
                pq.push({m.second,m.first});
            }else{
                if(pq.top().first < m.second){
                    pq.pop();
                    pq.push({m.second,m.first});
                }else if(pq.top().first == m.second && pq.top().second > m.first){
                    pq.pop();
                    pq.push({m.second,m.first});
                }
            }
        }

        vector<string>result(k);
        int i = 0;
        while(pq.size()>0){
            result[i] = pq.top().second;
            pq.pop();
            i++;
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
