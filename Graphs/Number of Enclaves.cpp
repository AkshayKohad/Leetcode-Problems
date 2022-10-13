class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                    
                    else
                    count++;
                }
            }
        }
        
     //cout<<count<<endl;    
        
        while(q.empty()==false)
        {
            pair<int,int>cur = q.front();
            
            q.pop();
            
            int i = cur.first;
            int j = cur.second;
            
            for(auto k:directions)
            {
                int x = i+k.first;
                int y = j+k.second;
                
                if(x>=n || y>=m || x<0 || y<0 ||grid[x][y]==0 || visited[x][y]==1 )
                {
                    continue;
                }
                
                q.push({x,y});
                visited[x][y] = 1;
                count--;
            }
            
        }
        
        return count;
    }
};
