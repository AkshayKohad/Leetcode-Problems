class Solution {
public:
    int solve(vector<int>&prices,int i,int buy,vector<vector<int>>&memo)
    {
        
        if(i==prices.size())
            return 0;
        
        
        if(memo[i][buy]!=-1)
            return memo[i][buy];
        
        long long int profit = 0;
        
        if(buy)
        {
            profit = max(-prices[i] + solve(prices,i+1,0,memo),0 + solve(prices,i+1,1,memo));
        }
        
        
        else{
            profit = max(prices[i] + solve(prices,i+1,1,memo),0 + solve(prices,i+1,0,memo));
        }
        
        return memo[i][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>memo(n,vector<int>(2,-1));
        return solve(prices,0,1,memo);
    }
};
