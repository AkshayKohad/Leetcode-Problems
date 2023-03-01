class Solution {
public:

  #define pii pair<int,pair<int,int>>
  vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int minimumTime(vector<vector<int>>& grid) {

     if(grid[0][1]>1 && grid[1][0]>1)
     return -1;

     int n = grid.size();
     int m = grid[0].size();

     priority_queue<pii,vector<pii>,greater<pii>>pq;
     
     vector<vector<int>>visited(n,vector<int>(m,0));

     pq.push({0,{0,0}});
     
     while(pq.empty()==false)
     {
         pair<int,pair<int,int>>cur = pq.top();
         pq.pop();

         int time_sec = cur.first;
         int i = cur.second.first;
         int j = cur.second.second;

         if(i==n-1 && j==m-1)
         return time_sec;

         for(auto k:directions)
         {
             int x = i + k.first;
             int y = j + k.second;

             if(x<0 || y<0 || x>=n || y>=m || visited[x][y])
             continue;

             if(time_sec+1<grid[x][y])
             {
                 int time_diff = grid[x][y] - time_sec;

                 if(time_diff%2==1)
                 {
                     pq.push({grid[x][y],{x,y}});
                     visited[x][y] = 1;
                 }

                 else{
                     pq.push({grid[x][y]+1,{x,y}});
                     visited[x][y] = 1;
                 }
             }

             else{
                 pq.push({time_sec+1,{x,y}});
                 visited[x][y] = 1;
             }

         }
     }
    
    return -1;
    }
};
