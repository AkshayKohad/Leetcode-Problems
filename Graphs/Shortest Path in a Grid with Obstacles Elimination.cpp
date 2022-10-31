class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        vector<vector<vector<int>>>visited(n,vector<vector<int>>(m,vector<int>(k+1,0)));
                                           
           visited[0][0][k] = 1;
                                           
                                           
            queue<pair<int,pair<int,int>>>q;
                                           
             q.push({k,{0,0}});
                                           
              
               int steps = 0;                            
         while(q.empty()==false)
           {
               int size = q.size();
               
               while(size--)
               {
                   
               pair<int,pair<int,int>>cur = q.front();
               q.pop();
               
               int moves = cur.first;
               int i = cur.second.first;
               int j = cur.second.second;
                   
                if(i== n-1 && j== m-1)
                    return steps;
                   
                for(auto d : directions)
                {
                    int x = d.first + i;
                    int y = d.second + j;
                    
                    if(x>=n || y>=m || x<0 || y<0 )
                    {
                        continue;
                    }
                    
                    if(grid[x][y]==1)
                    {
                        if(moves<=0)
                        {
                            continue;
                        }
                        
                        else{
                            if(visited[x][y][moves-1]==1)
                            {
                               continue;    
                            }
                            
                            visited[x][y][moves-1] = 1;
                            q.push({moves-1,{x,y}});
                            
                        }
                    }
                    
                    else{
                        if(visited[x][y][moves]==1)
                        {
                            continue;
                        }
                        visited[x][y][moves] = 1;
                        q.push({moves,{x,y}});
                    }
                }
                   
               }
               steps++;
           }        
                return -1;                           
    }
};
