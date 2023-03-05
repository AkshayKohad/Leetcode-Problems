class Solution {
public:
    
    
    // For this solution we will merge all overlapping Interval
    // find the total intervals after merging let's say n. so answer will be 2^n
    
    #define ll long long 
    #define mod 1000000007
    
    static bool mycmp(vector<int>&f,vector<int>&s)
    {
        if(f[0]==s[0])
            return f[1]<s[1];
        
        return f[0]<s[0];
    }
    
    ll power(ll a,int n)
    {
        if(n==1)
        {
            return a%mod;
        }
        
        if(n%2==1)
        {
            ll val = power(a,(n-1)/2);
            
            return (val*val*a)%mod;
        }
        
        else{
            ll val = power(a,n/2);
            val = val%mod;
            return (val*val)%mod;
        }
        
        return 0;
    }
    
    
    int countWays(vector<vector<int>>& ranges) {
        
        sort(ranges.begin(),ranges.end(),mycmp);
        
        vector<pair<ll,ll>>merge_overlap;
        
        
        
        merge_overlap.push_back({ranges[0][0],ranges[0][1]});
        
        
        
        for(int i=1;i<ranges.size();i++)
        {
            pair<ll,ll>cur = merge_overlap.back();
            
           
            if(cur.second>=ranges[i][0])
            {
                
                if(cur.second<ranges[i][1])
                {
                    merge_overlap.back().second = ranges[i][1];
                }
                
               
            }
            
            else{
                merge_overlap.push_back({ranges[i][0],ranges[i][1]});
            }
            
        }
        
        int n = merge_overlap.size();
      
        
        
        
        int result = power(2,n);
        
        return result;
    }
};
