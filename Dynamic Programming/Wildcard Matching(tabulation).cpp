class Solution {
public:
    bool isMatch(string str, string pattern) {
        int m = pattern.length();
        int n = str.length();
        
        int dp[n+1][m+1];
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        
        for(int j=1;j<=m;j++)
        {
            if(pattern[j-1]=='*')
            dp[0][j] = dp[0][j-1];
            else
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str[i-1]==pattern[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else{
                    if(pattern[j-1]=='?')
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    
                    else if(pattern[j-1]=='*')
                    {
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                    }
                    
                    else
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[n][m];
    }
};
