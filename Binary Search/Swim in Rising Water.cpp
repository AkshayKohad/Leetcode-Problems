class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool check(int &t,vector<vector<int>>&grid,int &n)
    {
        if(grid[0][0]>t)
        {
            return false;
        }
        
        if(n-1 == 0 && n-1 == 0)
            return true;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        
        while(q.empty()==false)
        {
            pair<int,int>cur = q.front();
            
            q.pop();
            
            int i = cur.first;
            int j = cur.second;
            
//             if(i==n-1 && j==n-1)
//                 return true;
            
            
            for(auto k:directions)
            {
                int x = i+k.first;
                
                int y = j+k.second;
                
                if(x<0 || y<0 || x>=n || y>=n || visited[x][y]==1)
                    continue;
                
                
                if(grid[x][y]>t)
                    continue;
                
                if(x==n-1 && y==n-1)
                    return true;
                
                q.push({x,y});
                visited[x][y] = 1;
                
            }
        }
        
        return false;
    }
    
    
    int swimInWater(vector<vector<int>>& grid) {
     
        
        int l = 0;
        int r = 0;
        
        int n = grid.size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mini = min(mini,grid[i][j]);
                
                maxi = max(maxi,grid[i][j]);
            }
        }
        
        r = maxi - mini;
        
        int ans = -1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
           // cout<<mid<<endl;
            if(check(mid,grid,n))
            {
                ans = mid;
                
                r = mid-1;
            }
            
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};
