class Solution {
public:
    
        vector<pair<int,int>>directions = {{1,0},{0,1},{0,-1},{-1,0}};
    
    int dfs(int i,int j,vector<vector<int>>matrix,vector<vector<int>>&memo)
    {
        
        if(memo[i][j]>0)
            return memo[i][j];
        
        int res = 0;
        //int ans = 0;
         for(auto k:directions)
            {
                int x = i+k.first;
                int y = j+k.second;
                
                
                if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size() || matrix[i][j]>=matrix[x][y])
                {
                    res = max(res,0);
                    continue;
                }
                
                //q.push({val+1,{x,y}});
                
                res = max(res,dfs(x,y,matrix,memo));
            
            }
        
        return memo[i][j] = 1+res;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>memo(n,vector<int>(m,0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                
                res = max(res,dfs(i,j,matrix,memo));
               
            }
        }
        
        
        return res;
    }
};
