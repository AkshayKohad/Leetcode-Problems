class Solution {
public:
    
    int MOD = 1000000007;
    #define ll long long
    
    static bool mycmp(pair<int,int>f,pair<int,int>s)
    {
        if(f.first == s.first)
            return f.second>s.second;
        
        return f.first > s.first;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>>res;
        
        for(int i=0;i<n;i++)
        {
            res.push_back({efficiency[i],speed[i]});
        }
        sort(res.begin(),res.end(),mycmp);
        
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        ll total_speed = 0;
        
        ll ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
           pair<int,int>cur = res[i];
            
            int cur_efficiency = res[i].first;
            
            int cur_speed = res[i].second;
            if(pq.size()==k)
            {
              total_speed -= pq.top();
                
                pq.pop();
                
                
            }
            
            pq.push(cur_speed);
            
            total_speed += cur_speed;
            
            ll cur_ans = (total_speed*cur_efficiency); 
            
            
            ans = max(ans,cur_ans);
        }
        
        return ans%MOD;
    }
};
