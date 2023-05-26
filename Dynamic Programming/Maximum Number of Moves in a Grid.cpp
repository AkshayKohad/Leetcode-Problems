class Solution {
public:
    
    vector<pair<int,int>>directions = {{-1,1},{0,1},{1,1}};
    
    bool check(int i,int j,int val,vector<vector<int>>&grid,int &n,int &m)
    {
        
          
            
            if(i<0 || i>=n || j<0 || j>=m)
                return true;
            
             if(grid[i][j]<=val)
             { 
                
                 return true;
             }
        
        return false;
           
        
    }
    
    int solve(int i,int j,vector<vector<int>>&grid,int &n,int &m,vector<vector<int>>&memo)
    {
        
            
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int res = 0;
        for(auto k:directions)
        {
            int x = i+k.first;
            int y = j+k.second;
            
            if(!check(x,y,grid[i][j],grid,n,m))
            {
               
            res = max(res,solve(x,y,grid,n,m,memo));
            }
            
        }
       
        return memo[i][j] = res+1;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        
        
        int result = 0;
        for(int i=0;i<n;i++)
        {
            result = max(result,solve(i,0,grid,n,m,memo)-1);
        }
        
        return result;
    }
};
