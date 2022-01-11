class Solution {
public:
    
    
    int solve(string text1,string text2,int m,int n)
    {
        if(m==0 || n==0)
            return 0;
        
        int ans1;
        if(text1[m-1]==text2[n-1])
            ans1 = solve(text1,text2,m-1,n-1)+1; 
        else
        ans1=0;
        
        int ans2 = solve(text1,text2,m-1,n);
        int ans3 = solve(text1,text2,m,n-1);
        
        return max(ans1,max(ans2,ans3));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.length();
        int n = text2.length();
        
        
        int dp[m+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        
         for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int ans1;
                if(text1[i-1]==text2[j-1])
                {
                    ans1 = dp[i-1][j-1]+1;
                }
                
                else{
                    ans1=0;
                }
                
                int ans2 = dp[i-1][j];
                int ans3 = dp[i][j-1];
                
                dp[i][j] = max(ans1,max(ans2,ans3));
            }
        }
        
        return dp[m][n];
        //return solve(text1,text2,m,n);
    }
};
