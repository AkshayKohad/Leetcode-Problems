class Solution {
public:
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
      //  return solve(amount,coins,n);
        
        int dp[amount+1][n+1];
        
        for(int i=0;i<=n;i++)
            dp[0][i] = 0;
        
        for(int j=0;j<=amount;j++)
            dp[j][0] = -1;
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int res;
                int res2;
                 if(i-coins[j-1]<0)
                 {
                     res=-1;
                 }
                
                 else{
                     res = dp[i-coins[j-1]][j];
                 }
                
                res2 = dp[i][j-1];
                
                if(res==-1 && res2==-1)
                    dp[i][j] = -1;
                
                else if(res==-1)
                    dp[i][j] = res2;
                
                else if(res2==-1)
                    dp[i][j] = res+1;
                
                else{
                    dp[i][j] = min(1+res,res2);
                }
            }
        }
        
        return dp[amount][n];
    }
};
