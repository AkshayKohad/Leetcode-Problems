class Solution {
public:
    
    
    int solve(vector<int>& prices,int i,int buy,int k,vector<vector<vector<int>>>&memo)
    {
       if(i==prices.size())
           return 0;
        
        if(k==0)
            return 0;
        
        if(memo[i][buy][k]!=-1)
            return memo[i][buy][k];
        
        long long int profit = 0;
        if(buy)
        {
            profit = max(-prices[i]+solve(prices,i+1,0,k,memo),0 + solve(prices,i+1,1,k,memo));
        }
        
        else
        {
            profit = max(prices[i]+solve(prices,i+1,1,k-1,memo),0 + solve(prices,i+1,0,k,memo));
        }
        
        return memo[i][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
     
        
        int n = prices.size();
        int k = 2;
        
        vector<vector<int>>after(2,vector<int>(3,0));
        vector<vector<int>>cur(2,vector<int>(3,0));
     //   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        //return solve(prices,0,1,k,memo);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int j=1;j<=2;j++)
                {
                    if(buy)
                    {
                        cur[buy][j] = max(-prices[i] + after[0][j], after[1][j]);
                    }
                    
                    else{
                        cur[buy][j] = max(prices[i]+after[1][j-1],after[0][j]);
                    }
                }
            }
            after = cur;
        }
        
        return cur[1][2];
    }
};
