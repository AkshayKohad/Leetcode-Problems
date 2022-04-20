class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}}; 
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        int count_oranges = 0;
      vector<pair<int,int>>rotten_oranges;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {

                
                 if(grid[i][j]==1)
                 {
                     count_oranges++;
                 }
                
                else if(grid[i][j]==2)
                {
                    rotten_oranges.push_back( make_pair(i,j));
                }
            }
        }
        
        
        
        for(int i=0;i<rotten_oranges.size();i++)
        {
            queue<pair<pair<int,int>,int>>q;
          int x = rotten_oranges[i].first;
            int y = rotten_oranges[i].second;
            
            q.push({{x,y},0});
            
            while(q.empty()==false)
            {
                pair<pair<int,int>,int>curr = q.front();
                q.pop();
                
                int moves = curr.second;
                int x1 = curr.first.first;
                int y1 = curr.first.second;
                
                for(auto k : directions)
                {
                    int x2 = x1 + k.first;
                    
                    int y2 = y1 + k.second;
                    
                    if(x2<0 || y2<0 || x2>=m || y2>=n || grid[x2][y2]==0 || grid[x2][y2] ==2 )
                        continue;
                    
                    if(visited[x2][y2]==0)
                    {
                        visited[x2][y2] = moves+1;
                        q.push({{x2,y2},moves+1});
                        count_oranges--;
                    }
                    
                    else{
                        if(visited[x2][y2]>moves+1)
                        {
                            visited[x2][y2] = moves+1;
                            q.push({{x2,y2},moves+1});
                            
                        }
                    }
                }
                
            }
        }
    
        if(count_oranges>0)
            return -1;
        
    
        
        
               int res = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res = max(res,visited[i][j]);
            }
        }
        
     return res;
    }
};
