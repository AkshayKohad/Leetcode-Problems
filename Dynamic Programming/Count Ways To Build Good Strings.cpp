class Solution {
public:
     
    #define MOD 1000000007
    
    int solve(int n,int &zero,int &one,vector<int>&memo)
    {
         if(n<0)
            return 0;
       
        
        if(n==0)
            return 1;
        
       if(memo[n]!=-1)
           return memo[n];
    
        int sum = 0;
         sum = (solve(n-zero,zero,one,memo)%1000000007 + solve(n-one,zero,one,memo)%1000000007)%1000000007;
        
        return memo[n] = sum;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
     
        vector<int>memo(high+1,-1);
        
        int n = high;
        solve(n,zero,one,memo);
        
        int res = 0;
        
        for(int i=low;i<=high;i++)
        {
            res = (res + solve(i,zero,one,memo))%1000000007;
        }
       
        return res;
    }
};
