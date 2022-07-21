class Solution {
public:
    
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>& heights,int diff,int n,int m)
    {
        if(i==n-1 && j==m-1)
            return true;
        
        for(auto k:directions)
        {
            int x = i + k.first;
            int y = j + k.second;
            
            if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==1)
                continue;
            
            if(abs(heights[x][y]-heights[i][j])>diff)
                continue;
            
            visited[x][y] = 1;
            if(dfs(x,y,visited,heights,diff,n,m))
                return true;
               
        }
        
        return false;
        
        
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
     
        int l = 0;
        int h = INT_MAX;
        
        int n = heights.size();
        int m = heights[0].size();
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 h = max(h,heights[i][j]);
//             }
//         }
        
        int ans = INT_MAX;
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            vector<vector<int>>visited(n,vector<int>(m,0));
            visited[0][0] = 1;
            
            if(dfs(0,0,visited,heights,mid,n,m))
            {
                h  = mid-1;
                ans = min(mid,ans);
            }
            
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};
