class Solution {
public:
    int numTrees(int n) {
        
        if(n==1)
            return 1;
        
        if(n==2)
            return 2;
        int dp[n+1];
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        if(n<=2)
        {
            return dp[n];
        }
        
        for(int i=3;i<=n;i++)
        {
            int count1 = i-1;
            int count2 = 0;
            int total =0;
            while(count1>=0)
            {
                total += dp[count1]*dp[count2];
                count1--;
                count2++;
            }
            
            dp[i] = total;
        }
        
        return dp[n];
    }
};
