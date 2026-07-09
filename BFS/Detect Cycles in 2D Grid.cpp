class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    queue<vector<int>>q;
                    q.push({i,j,-1,-1,grid[i][j]-'a'});
                    visited[i][j] = 1;
                    while(q.empty()==false){
                        vector<int>cur = q.front();
                        int cur_x = cur[0];
                        int cur_y = cur[1];
                        int par_x = cur[2];
                        int par_y = cur[3];
                        int ch = cur[4];

                        q.pop();

                        for(auto dir : directions){
                            int x = cur_x + dir.first;
                            int y = cur_y + dir.second;

                            if(x<0 || y<0 || x>=n || y>=m || grid[x][y]-'a' != ch)continue;

                            if(x==par_x && y==par_y)continue;

                            if(visited[x][y])return true;
                            visited[x][y] = 1;
                            q.push({x,y,cur_x,cur_y,ch});
                        }
                    }
                }
            }
        }

        return false;
    }
};
