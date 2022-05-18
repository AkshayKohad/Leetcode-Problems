class Solution {
public:
    // 3-Dimensional DP
    
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
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return solve(prices,0,1,k,memo);
    }
};
