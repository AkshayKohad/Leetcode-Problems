class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{0,-1},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        
        queue<pair<int,int>>q;
        int count=0;
        int m = grid[0].size();
        int n = grid.size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                    grid[i][j]='0';
                    
                    while(q.empty()==false)
                    {
                       pair<int,int>curr =  q.front();
                        int x = curr.first;
                        int y = curr.second;
                        q.pop();
                        
                        for(auto k:directions)
                        {
                            int x_next = x + k.first;
                            int y_next = y + k.second;
                            
                            if(x_next>=n || x_next<0 || y_next>=m || y_next<0 || grid[x_next][y_next]=='0')
                                continue;
                            
                            q.push({x_next,y_next});
                            grid[x_next][y_next]='0';
                        }
                    }
                    count++;
                }
                
                else
                    continue;
            }
        }
        
        return count;
    }
};
