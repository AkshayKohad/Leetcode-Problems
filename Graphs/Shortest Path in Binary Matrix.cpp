class Solution {
public:

  vector<pair<int,int>>directions= {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        

        vector<vector<int>>visited(n,vector<int>(n,INT_MAX));

        if(grid[0][0]==1)return -1;

        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        visited[0][0] = 1;


         while(q.empty()==false)
         {
             pair<int,pair<int,int>>cur = q.front();
             q.pop();
             
             int moves = cur.first;
             int i = cur.second.first;
             int j = cur.second.second;


             if(i==n-1 && j==n-1)
             return moves;

             for(auto k:directions)
             {
                 int x = i+k.first;
                 int y = j+k.second;

                 if(x<0 || y<0 || x>=n || y>=n || grid[x][y]==1)
                 continue;

                 if(visited[x][y]<= moves+1)
                 continue;

                 visited[x][y] = moves+1;
                 q.push({moves+1,{x,y}});
             }
         }

         return -1;

    }
};
