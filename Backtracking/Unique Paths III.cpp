class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    void solve(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited,int count,int &res,int n,int m)
    {
        if(grid[i][j]==2)
        {
            if(count==0)
                res++;
            
            return;
        }
        
        for(auto k:directions)
        {
            int x = i + k.first;
            int y = j + k.second;
            
            
            if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==true || grid[x][y]==-1)
            {
                continue;
            }
            
            
            visited[x][y] = true;
            
            solve(x,y,grid,visited,count-1,res,n,m);
            
            visited[x][y] = false;
            
            
        }
    }
    
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
      
        int n = grid.size();
        
        int m = grid[0].size();
        
        
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int x;
        int y;
        
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    x = i;
                    y = j;
                }
                
                else if(grid[i][j]==2 || grid[i][j]==0)
                {
                    count++;
                }
                
                
            }
                 
                
        }
        
        
        int res = 0;
            
            visited[x][y] = true;
            
            solve(x,y,grid,visited,count,res,n,m);
        
        return res;
    }
};
