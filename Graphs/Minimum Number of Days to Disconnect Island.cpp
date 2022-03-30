class Solution {
public:
    int startx,starty;
    vector<pair<int,int>>directions = {{1,0},{0,1},{0,-1},{-1,0}};
    int count_grid_ones;
    bool checkArticulation(vector<vector<int>>&grid,map<pair<int,int>,int>&discovery_time,map<pair<int,int>,int>&lowest,pair<int,int>cur,pair<int,int>par,int &timer)
    {
        discovery_time[cur] = lowest[cur] = timer++;
        
        int no_child = 0;
        
        int x = cur.first;
        int y = cur.second;
        int n = grid.size();
        int m = grid[0].size();
        for(auto k:directions)
        {
            int x1 = x + k.first;
                
            int y1 = y + k.second;
                
                if(x1<0 || y1<0 || x1>=n || y1>=m || grid[x1][y1]==0)
                    continue;
            
            pair<int,int>child = make_pair(x1,y1);
              if(discovery_time.find(child) == discovery_time.end())
              {
                  bool flag = checkArticulation(grid,discovery_time,lowest,child,cur,timer);
                  no_child++;
                      
                      if(flag==true)
                          return true;
                  
                  lowest[cur] = min(lowest[cur],lowest[child]);
                  
                  if(par.first != -1 && par.second!= -1 && lowest[child]>=discovery_time[cur])
                      return true;
              }
            
              else if(child!=par)
              {
                  //backedge condition
                  
                  lowest[cur] = min(lowest[cur],discovery_time[child]);
              }
        }
        
        
        
        
        if(par.first == -1 && par.second == -1 && no_child>=2)
            return true;
        
        
        return false;
    }
    
    
    bool isArticulation(vector<vector<int>>&grid)
    {
        map<pair<int,int>,int>discovery_time;
        map<pair<int,int>,int>lowest;
        
        int timer = 0;
        
        pair<int,int>par = {-1,-1};
        pair<int,int>cur = {startx,starty};
        bool res = checkArticulation(grid,discovery_time,lowest,cur,par,timer);
        
        
        return res;
    }
    
    
    bool isDisconnect(vector<vector<int>>&grid)
    {
        int count = 0;
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int flag=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                    
                    if(flag==0)
                    {
                        startx = i;
                        starty = j;
                        q.push({i,j});
                        visited[i][j] = 1;
                        flag=1;
                        
                    }
                }
            }
        }
        
        int c = 1;
      //  cout<<startx<<" "<<starty<<endl;
       // cout<<endl;
        while(q.empty()==false)
        {
            pair<int,int>curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            for(auto k : directions)
            {
               int  x1 = x + k.first;
                
               int  y1 = y + k.second;
                
             //   cout<<x<<" -> "<<y<<endl;
                
                if(x1<0 || y1<0 || x1>=n || y1>=m || visited[x1][y1]==1 || grid[x1][y1]==0)
                    continue;
                
               // cout<<x<<" "<<y<<endl;
                q.push({x1,y1});
                visited[x1][y1] = 1;
                c++;
            }
        }
        //cout<<count<<endl;
        //cout<<c<<endl;
        
        count_grid_ones = count;
        
       if(count==c)
           return false;
        
        else
            return true;
    }
    int minDays(vector<vector<int>>& grid) {
        
        if(isDisconnect(grid))
            return 0;
        
        if(isArticulation(grid) || count_grid_ones == 1)
            return 1;
        
        return 2;
        
        
        
    }
};
