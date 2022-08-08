class Solution {
public:
    
    int LCS(string &s,string &t,int n,int m)
    {
        if(n==0 || m==0)
            return 0;
        
        if(s[n-1]==t[m-1])
        {
           return  max({1+LCS(s,t,n-1,m-1),LCS(s,t,n-1,m),LCS(s,t,n,m-1)});
        }
        
        else{
            return max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        
        
        // This question can be solved using LCS (Longest common subsequence)
        
        // so what we do is we make one more string which will be reverse of input string
        
        // and we will find LCS of this 2 strings it will give us Longest Palindromic                 // Subsequence
        
        
        string t = s;
        
        reverse(t.begin(),t.end());
        
        
        int n = s.length();
      //  return LCS(s,t,n,n);
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
            
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = max({1+dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
                
                
                else{
                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
};
