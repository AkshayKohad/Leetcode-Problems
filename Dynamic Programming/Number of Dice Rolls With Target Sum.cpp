class Solution {
public:
    
    int mod = 1000000007;
    int solve(int n,int &k,int target)
    {
      if(n==0 && target==0)
          return 1;
        
        if(n==0) return 0;
        
        if(target<=0) return 0;
        
        int res = 0;
        for(int i=1;i<=k;i++)
        {
            res = (res + solve(n-1,k,target-i))%mod;
        }
        
        return res;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        int dp[n+1][target+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        
        for(int i=0;i<=target;i++)
        {
           dp[0][i] = 0;
        }
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int res = 0;
                for(int l=1;l<=k;l++)
                {
                    if(j-l<0)
                        continue;
                    
                    res = (res + dp[i-1][j-l])%mod;
                }
                
                dp[i][j] = res;
            }
                
        }
        
        return dp[n][target];
      // return solve(n,k,target);
    }
};
