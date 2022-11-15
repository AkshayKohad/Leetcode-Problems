class Solution {
public:
    
    int solve(int i,vector<int>&prices,int &n,vector<int>&memo)
    {
        if(i>=n)
            return 0;
        
        if(memo[i]!=-1)
            return memo[i];
        
        int res = 0;
        
        for(int j=i+1;j<n;j++)
        {
          int ans = prices[j]-prices[i] + solve(j+2,prices,n,memo);
            
            res = max(res,ans);
        }
        
        res = max(res,solve(i+1,prices,n,memo));
        return memo[i] = res;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int>memo(n+1,-1);
        return solve(0,prices,n,memo);
    }
};
