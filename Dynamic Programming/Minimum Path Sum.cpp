class Solution {
public:
    
    vector<pair<int,int>>directions = {{-1,0},{0,-1}};
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
       // vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
       // return solve(n,m,grid,memo);
        
       int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = INT_MAX;
        }
        
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = INT_MAX;
        }
        
        dp[1][1] = grid[0][0];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1 && j==1)
                    continue;
                
         int res = INT_MAX;
        for(auto k:directions)
        {
            int x = i + k.first;
            int y = j + k.second;
            
            
            
            res = min(res,dp[x][y]);
            
        }
                
                if(res==INT_MAX)
                    dp[i][j] = INT_MAX;
                
                else{
                    dp[i][j] = res + grid[i-1][j-1];
                }
                
            }
        }
        
        return dp[n][m];
    }
};
