class Solution {
public:
    
    
   
    int maxProfit(vector<int>& prices) {
     
        
        int n = prices.size();
        int k = 2;
        
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        //return solve(prices,0,1,k,memo);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int j=1;j<=2;j++)
                {
                    if(buy)
                    {
                        dp[i][buy][j] = max(-prices[i] + dp[i+1][0][j], dp[i+1][1][j]);
                    }
                    
                    else{
                        dp[i][buy][j] = max(prices[i]+dp[i+1][1][j-1],dp[i+1][0][j]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};
