class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
     int n = grid.size();
     int m = grid[0].size();   
     vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
     queue<vector<int>>q;
     visited[0][0] = grid[0][0];
     q.push({0,0,grid[0][0]});
     while(q.empty()==false){
        vector<int>cur = q.front();
        q.pop();
        int cur_x = cur[0];
        int cur_y = cur[1];
        int cur_h = cur[2];

        if(cur_x == n-1 && cur_y == m-1)continue;

        for(auto dir : directions){
            int x = cur_x + dir.first;
            int y = cur_y + dir.second;

            if(x<0 || y<0 || x>=n || y>=m)continue;

            if(cur_h + grid[x][y] < visited[x][y]){
                visited[x][y] = cur_h + grid[x][y];
                q.push({x,y,cur_h+grid[x][y]});
            }
        }
     }

     if(visited[n-1][m-1]<health)return true;
     return false;
     
    }   
    
};
