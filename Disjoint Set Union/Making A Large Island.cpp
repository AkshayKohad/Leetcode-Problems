class Solution {
public:
    
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    
    
    pair<int,int> find(pair<int,int>w,vector<vector<pair<int,int>>>&parent)
    {
        if(parent[w.first][w.second].first == -1 && parent[w.first][w.second].second == -1)
            return w;
        
        return parent[w.first][w.second] = find(parent[w.first][w.second],parent);
    }
    
    void unite(pair<int,int>p,pair<int,int>r, vector<vector<pair<int,int>>>&parent,vector<vector<int>>&rank)
    {
        pair<int,int> parent1 = find(p,parent);
        
        pair<int,int> parent2 = find(r,parent);
        
        if(parent1 != parent2 || (parent1 == parent2  &&  parent1.first == -1  && parent1.second == -2  ))
        {
            if(rank[parent1.first][parent1.second]>rank[parent2.first][parent2.second])
            {
                rank[parent1.first][parent1.second] += rank[parent2.first][parent2.second];
                
                parent[parent2.first][parent2.second] = {parent1.first,parent1.second};
                
            }
            
            
            else{
                
                rank[parent2.first][parent2.second] += rank[parent1.first][parent1.second];
                
                parent[parent1.first][parent1.second] = {parent2.first,parent2.second};
                
            }
        }
    }
    
    void bfs(int i,int j,vector<vector<bool>>&visited,vector<vector<pair<int,int>>>&parent,vector<vector<int>>&rank,vector<vector<int>>& grid,int &n,int &m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        
        visited[i][j];
        
        while(q.empty()==false)
        {
            pair<int,int>curr = q.front();
            q.pop();
            
            int i = curr.first;
            
            int j = curr.second;
            
            
            
           
            
            for(auto k : directions)
            {
                int x = i+k.first;
                
                int y = j+k.second;
                
                if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==true || grid[x][y]==0)
                    continue;
                
                pair<int,int>p = {i,j};
                pair<int,int>r = {x,y};
                
                unite(p,r,parent,rank);
                
                q.push({x,y});
                
                visited[x][y] = true;
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>rank(n,vector<int>(m,1));
        
        vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
        
        queue<pair<int,int>>zero;
        
        
        
         vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(visited[i][j]==false)
                    {
                        bfs(i,j,visited,parent,rank,grid,n,m);
                    }
                }
                
                else{
                    zero.push({i,j});
                }
            }
        }
        
       
        
        
        
        
        int res = 0;
        
        // initializing res with biggest island because if zero is empty then answer will be largest island
        // that is maximum value of rank
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res = max(res,rank[i][j]);
                
               // cout<<rank[i][j]<<" ";
            }
          //  cout<<endl;
        }
        
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cout<<"("<<parent[i][j].first<<","<<parent[i][j].second<<") ";
//             }
            
//             cout<<endl;
//         }
        
        while(zero.empty()==false)
        {
            pair<int,int>curr = zero.front();
            zero.pop();
            
            int i = curr.first;
            
            int j = curr.second;
            
            int ans = 0;
            
            set<pair<int,int>>s;
            for(auto k:directions)
            {
                int x = k.first + i;
                int y = k.second + j;
                
                if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0)
                {
                    continue;
                }
                
                pair<int,int>t = {x,y};
                pair<int,int>parent_find  = find(t,parent);
                
                s.insert(parent_find);
               // ans += rank[parent_find.first][parent_find.second];
                
                
            }
            
            for(auto f:s)
            {
                ans += rank[f.first][f.second];
            }
            
            
            res = max(res,ans+1);
        }
        
        return res;
        
        
    }
};
