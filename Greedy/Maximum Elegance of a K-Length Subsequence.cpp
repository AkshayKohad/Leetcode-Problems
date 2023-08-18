class Solution {
public:
    
    #define ll long long
    
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
     
        
        sort(items.begin(),items.end(),greater<vector<int>>());
        
        unordered_map<ll,ll>mp;
        
        int n = items.size();
        ll sum = 0;
        
        ll distinct = 0;
        
        for(int i=0;i<k;i++)
        {
           sum += items[i][0];
            
           if(mp[items[i][1]]==0)
               distinct++;
            
           mp[items[i][1]]++;
            
        }
        
        distinct = mp.size();
        
        ll result = sum + distinct*distinct;
        
          int j=k-1;
        for(int i=k;i<n;i++)
        {
            ll profit = items[i][0];
            ll category = items[i][1];
            
            if(mp.find(category)==mp.end())
            {
              
                
                while(j>=0 && mp[items[j][1]]<2)j--;
                
                if(j<0) break;
                
                sum = sum-items[j][0];
                
                mp[items[j][1]]--;
                
                mp[category]++;
                
                sum += profit;
                
                distinct = distinct + 1;
                result = max(result,sum + distinct*distinct);
                j--;
                
            }
        }
        
        return result;
    }
};
