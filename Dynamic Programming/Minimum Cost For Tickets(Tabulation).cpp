class Solution {
public:
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int m = days[n-1];
        int dp[n+1][m+1];
        
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(days[i-1]>j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                
                else if(days[i-1]<j)
                {
                    dp[i][j] = dp[i][days[i-1]];
                }
                
                else{
                    
                    int res;
                    if(j-1>=0)
                    {
                        res=dp[i][j-1];
                    }
                    
                    else{
                        res=0;
                    }
                    int ans = costs[0] + res;
                    
                    
                     if(j-7>=0)
                    {
                        res=dp[i][j-7];
                    }
                    
                    else{
                        res=0;
                    }
            int ans1 = costs[1] + res;
                    
                    
                     if(j-30>=0)
                    {
                        res=dp[i][j-30];
                    }
                    
                    else{
                        res=0;
                    }
            int ans2 = costs[2] + res;
            
            int ans3 = min(ans1,ans);
            int ans4 = min(ans2,ans3);
                    
                    dp[i][j] = ans4;
                }
            }
        }
        
        return dp[n][m];
        
        
    }
};
