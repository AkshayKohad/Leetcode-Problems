class Solution {
public:
    #define ll long long
    
    #define MOD 1000000007
    int peopleAwareOfSecret(int n, int delay, int forget) {
     
        vector<ll>dp(n+1,0);
        
        dp[0] = 1;
        
        
        
        for(ll i=1;i<n;i++)
        {
            ll ans = 0;
            
            ll k=0;
            
            if(i-forget+1>0)
                k = i-forget+1;
            
            for(ll j = k;j<=i-delay;j++)
            {
                ans  = (ans + dp[j])%MOD;
                
            }
            
            dp[i] = ans;
        }
        
        
        ll res = 0;
        for(ll i = ((n-1)-forget+1); i<n;i++)
        {
            res = (res + dp[i])%MOD;
        }
        
        return res;
    }
};
