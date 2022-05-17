class Solution {
public:
    
    int solve(int m,int n,vector<vector<int>>& obstacleGrid)
    {
        
        
        if(m==0 && n==0)
            return 1;

        if(m<0)
            return 0;
        if(n<0)
            return 0;
        
        if(obstacleGrid[m][n]==1)
            return 0;

        return solve(m-1,n,obstacleGrid) + solve(m,n-1,obstacleGrid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
       // return solve(m-1,n-1,obstacleGrid);
        
        if(obstacleGrid[m-1][n-1]==1)
            return 0;
        
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
                    if(obstacleGrid[i-1][j]==1)
                        ans1 = 0;
                    else
                    ans1 = dp[i-1][j];
                }

                if(j-1<0)
                {
                    
                    ans2 = 0;
                }

                else{
                    
                    if(obstacleGrid[i][j-1]==1)
                        ans2 = 0;
                    else
                    ans2 = dp[i][j-1];
                }

                dp[i][j] = ans1 + ans2;
            }
        }

        return dp[m-1][n-1];
    }
};
