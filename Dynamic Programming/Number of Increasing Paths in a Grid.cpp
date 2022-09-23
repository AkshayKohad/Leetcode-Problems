class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    #define MOD 1000000007
    
    int solve(int i,int j,int &n,int &m,vector<vector<int>>&grid,vector<vector<int>>&memo)
    {
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int ans = 0;
        for(auto k:directions)
        {
            int x = i+k.first;
            int y = j+k.second;
            
            
            if(x<0 || y<0 || x>=n || y>=m || grid[i][j]>=grid[x][y])
                continue;
            
            ans = (ans + solve(x,y,n,m,grid,memo))%MOD;
        }
        
        return memo[i][j] = (ans+1)%MOD;
    }
    
    int countPaths(vector<vector<int>>& grid) {
    
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        int res = 0;
        
        cout<<n<<endl;
        
        vector<vector<int>>memo(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res = (res + solve(i,j,n,m,grid,memo))%MOD;
            }
        }
        
        
        return  res;
    }
};
