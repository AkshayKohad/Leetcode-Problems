class Solution {
public:
    
    int solve(int amount,vector<int>&coins,int n,vector<vector<int>>&memo)
    {
            if(amount==0)
                return 1;
        
           if(amount<0)
               return 0;
        
        if(n==0)
            return 0;
        
        if(memo[amount][n]!=-1)
            return memo[amount][n];
        
        
        return memo[amount][n] = solve(amount,coins,n-1,memo) + solve(amount-coins[n-1],coins,n,memo);
        
        
            
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>memo(amount+1,vector<int>(n+1,-1));
        return solve(amount,coins,n,memo);
    }
};
