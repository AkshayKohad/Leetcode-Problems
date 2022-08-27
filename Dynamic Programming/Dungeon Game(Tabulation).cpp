class Solution {
public:
    //bottom and right
    vector<pair<int,int>>directions = {{1,0},{0,1}};
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
     
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        int dp[n][m];
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) 
                {
                    dp[i][j] = min(0,dungeon[i][j]);
                    continue;
                }
                
                int res = INT_MIN;
                for(auto k:directions)
                {
                    int x = i+k.first;
                    int y = j+k.second;
                    
                    
                    if(x>=n || y>=m) continue;
                    
                    res = max(res,dp[x][y]);
                }
                
                dp[i][j] = min(0,res+dungeon[i][j]);
            }
        }
        
        
      
        return abs(dp[0][0]) +1;
    }
};
