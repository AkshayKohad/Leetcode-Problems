class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1}};
    
    
    int solve(int m,int n)
    {
        if(m==0 && n==0)
            return 1;
        
        if(m<0)
            return 0;
        if(n<0)
            return 0;
        
        return solve(m-1,n) + solve(m,n-1);
    }
    int uniquePaths(int m, int n) {
        
        //return solve(m-1,n-1);
        
        int dp[m][n];
        
        dp[0][0] = 1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                
                int ans1,ans2;
                if(i-1<0)
                {
                    ans1 = 0;
                }
                
                else{
                    ans1 = dp[i-1][j];
                }
                
                if(j-1<0)
                {
                    ans2 = 0;
                }
                
                else{
                    ans2 = dp[i][j-1];
                }
                
                dp[i][j] = ans1 + ans2;
            }
        }
        
        return dp[m-1][n-1];
    }
};
