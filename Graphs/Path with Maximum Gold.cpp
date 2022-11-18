class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int solve(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&grid,int &n,int &m)
    {
        visited[i][j] = 1;
        
        
        int gold = grid[i][j];
        
        int resulting_gold = 0;
        
        for(auto k:directions)
        {
            int x = k.first + i;
            int y = k.second + j;
            
            if(x>=n || y>=m || x<0 || y<0 ||visited[x][y]==1 || grid[x][y]==0)
                continue;
            
             resulting_gold =max(resulting_gold,solve(x,y,visited,grid,n,m));
            
        }
        
        visited[i][j] = 0;
        
        return gold+resulting_gold;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    visited[i][j]=1;
            }
        }
        
        int max_gold = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==1 || grid[i][j]==0)
                    continue;
                
                int cur_gold = solve(i,j,visited,grid,n,m);
                
                max_gold = max(cur_gold,max_gold);
            }
        }
        
        return max_gold;
    }
};
