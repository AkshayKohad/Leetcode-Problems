class Solution {
public:
   
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double >(m+1,0));
        
       
        int i,j;

        for(i=0;i<=n;i++)
            dp[i][0]=1;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
            
        }

        return dp[n][m];
    }
};





// Space Optimization 
// in O(N)


class Solution {
public:
   
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
       // vector<vector<double>>dp(n+1,vector<double >(m+1,0));
        vector<double>prev(m+1,0);
        vector<double>curr(m+1,0);
        
        prev[0] = curr[0] = 1;
        
        
       
        int i,j;

        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=prev[j-1]+prev[j];
                    
                }
                else
                    curr[j]=prev[j];
            }
            
            prev = curr;
            
        }

        return prev[m];
    }
};
