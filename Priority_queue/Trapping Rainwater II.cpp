
// https://www.youtube.com/watch?v=QvQiQcLCQ4Y


class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j] = true;
                }
            }
        }
        
        
        int ans = 0;
        int min_height = 0;
        
        while(pq.size()!=0)
        {
            int value = pq.top().first;
            
            int i = pq.top().second.first;
            
            int j = pq.top().second.second;
            
            min_height = max(value,min_height);
            
            pq.pop();
            
            for(auto k: directions)
            {
                int x = k.first + i;
                int y = k.second + j;
                
                
                if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==true)
                    continue;
                
                
                if(heightMap[x][y] < min_height)
                {
                    ans += min_height - heightMap[x][y];
                }
                
                visited[x][y] = true;
                
                pq.push({heightMap[x][y],{x,y}});
                    
            }
            
        }
       return ans;
    }
};
