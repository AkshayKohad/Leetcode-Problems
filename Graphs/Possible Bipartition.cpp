class Solution {
public:
    
    bool dfs(int src,vector<int>adj[],vector<int>&visited,int color)
    {
        visited[src] = color;
        
        for(auto u:adj[src])
        {
            if(visited[u]==0)
            {
                bool check = dfs(u,adj,visited,3-color);
                if(check==false)
                    return false;
                
            }
            
            else{
                if(visited[u]==color)
                    return false;
            }
        }
        
        return true;
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>adj[n+1];
        
        
        for(int i=0;i<dislikes.size();i++)
        {
            int x = dislikes[i][0];
            int y = dislikes[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            
        }
        
        vector<int>visited(n+1,0);
        
        
        for(int i=1;i<=n;i++)
        {
          if(visited[i]==0)
          {
              bool check = dfs(i,adj,visited,1);
              
              if(check==false)
                  return false;
          }
              
        }
        
        return true;
    }
};
