class Solution {
public:
    
    int solve(int i,vector<int>&prices,int &fee,int buy,int &n,vector<vector<int>>&memo)
    {
        if(i==n)
            return 0;
        
        if(memo[i][buy]!=-1)
            return memo[i][buy];
        
        if(buy==0)
        {
           return memo[i][buy] = max(-prices[i]-fee+solve(i+1,prices,fee,1,n,memo), 0+solve(i+1,prices,fee,0,n,memo));
        }
        
        else
        {
           return memo[i][buy]=max(prices[i]+solve(i+1,prices,fee,0,n,memo),0+solve(i+1,prices,fee,1,n,memo));
        }
        
        return 0;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>>memo(n,vector<int>(2,-1));
        return solve(0,prices,fee,0,n,memo);
    }
};
