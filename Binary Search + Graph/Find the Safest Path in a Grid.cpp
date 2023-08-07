class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool check(int min_limit,vector<vector<int>>& grid,vector<vector<int>>& safest_dist)
    {
        int n = grid.size();
        
        if(safest_dist[0][0]<min_limit || safest_dist[n-1][n-1]<min_limit) return false;
        
        
        queue<pair<int,int>>q;
    
        vector<vector<int>>visited(n,vector<int>(n,0));
        
        q.push({0,0});
        visited[0][0] = 1;
        
        while(q.empty()==false)
        {
            pair<int,int>cur = q.front();
            q.pop();
            
            int i = cur.first;
            int j = cur.second;
            
            if(i==n-1 && j==n-1) return true;
            
            for(auto k:directions)
            {
                int x = i+k.first;
                int y = j+k.second;
                
                
                if(x<0 || y<0 || x>=n || y>=n || visited[x][y]==1 || safest_dist[x][y]<min_limit)
                    continue;
                
                q.push({x,y});
                
                visited[x][y] = 1;
            }
        }
        
        return false;
    }
    
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1])
            return 0;
        
        
        queue<pair<int,pair<int,int>>>q;
        
        vector<vector<int>>safest_dist(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({0,{i,j}});
                    safest_dist[i][j] = 0;
                }
            }
        }
        
        int l = 0;
        int r = 0;
        
        while(q.empty()==false)
        {
            pair<int,pair<int,int>>cur = q.front();
            q.pop();
            
            int moves = cur.first;
            int i = cur.second.first;
            int j = cur.second.second;
            
            
            for(auto k:directions)
            {
                int x = i+k.first;
                int y = j+k.second;
                
                if(x<0 || y<0 || x>=n || y>=n || safest_dist[x][y]<=moves+1)
                continue;
            
                safest_dist[x][y] = moves+1;
                 r = max(r,moves+1);
                q.push({moves+1,{x,y}});
            }
            
            
        }
        
        int ans = -1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(check(mid,grid,safest_dist))
            {
             ans = mid;
             l = mid+1;   
            }
            
            else{
                r = mid-1;
            }
        }
        
        return ans;
        
        
        
    }
};
