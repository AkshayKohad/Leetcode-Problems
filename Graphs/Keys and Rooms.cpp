class Solution {
public:
    
    void dfs(int s,vector<bool>&visited,vector<int>adj[])
    {
        visited[s] = true;
        
        for(auto u:adj[s])
        {
            if(visited[u]==false)
            {
                dfs(u,visited,adj);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
       int n = rooms.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        
        int src = 0;
        
        vector<bool>visited(n,false);
        
        dfs(src,visited,adj);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
                return false;
        }
        
        return true;
    }
};
