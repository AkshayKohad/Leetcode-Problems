class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int minimumObstacles(vector<vector<int>>& grid) {
     
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        while(pq.size()>0)
        {
            pair<int,pair<int,int>>cur = pq.top();
            pq.pop();
            
            int moves = cur.first;
            
            int i = cur.second.first;
            
            int j = cur.second.second;
            
            if(i==n-1 && j==m-1)
            {
               // cout<<moves<<endl;
                //cout<<"hello"<<endl;
                continue;
            }
            for(auto k:directions)
            {
                int x = i+k.first;
                int y = j+k.second;
                
                //cout<<x<<" "<<y<<endl;
                if(x<0 || y<0 || x>=n || y>=m)
                    continue;
                
                if(grid[x][y]==1)
                {
                    if(dist[x][y] > moves + 1)
                    {
                        dist[x][y] = moves + 1; 
                        pq.push({moves+1,{x,y}});
                    }
                }
                
                
                else{
                    if(dist[x][y] > moves)
                    {
                          dist[x][y] = moves; 
                        pq.push({moves,{x,y}});   
                    }
                }
                
            }
        }
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<m;j++)
            //     {
            //         cout<<dist[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            return dist[n-1][m-1];
    }
};
