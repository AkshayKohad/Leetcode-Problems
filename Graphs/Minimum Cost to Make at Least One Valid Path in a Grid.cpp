class Solution {
public:
    
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
         unordered_map<int,pair<int,int>>mp;
        mp[1] = {0,1};
        mp[2] = {0,-1};
        mp[3] = {1,0};
        mp[4] = {-1,0};
        
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
       
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        
        dist[0][0] = 0;
        
        while(pq.size()>0)
        {
            pair<int,pair<int,int>>cur = pq.top();
            
            pq.pop();
            int cost = cur.first;
            
            int i = cur.second.first;
            
            int j = cur.second.second;
            
            if(i==n-1 && j==m-1)
            {
                continue;
            }
            
            
            int cur_dir = grid[i][j];
            for(auto k:mp)
            {
                int dir = k.first;
                pair<int,int>d = k.second;
                
                int x = i+d.first;
                int y = j+d.second;
                
                if(x>=n  || y>=m || x<0 || y<0)
                {
                    continue;
                }
                
                if(dir==cur_dir)
                {
                    if(dist[x][y] > cost)
                    {
                        dist[x][y] = cost;
                        pq.push({cost,{x,y}});
                    }
                }
                
                else{
                    
                    if(dist[x][y] > cost +1 )
                    {
                        dist[x][y] = cost+1;
                        pq.push({cost+1,{x,y}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};
