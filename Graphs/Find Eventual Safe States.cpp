class Solution {
public:
    void dfs(int s,vector<int>adj[],vector<int>&visited,vector<int>&rec_visited,vector<int>&res)
    {
        visited[s] = 1;
        rec_visited[s] = true;
        
        bool result = true;
        for(auto u :adj[s])
        {
            if(visited[u]==0)
            {
                 dfs(u,adj,visited,rec_visited,res);
                
                //if(ans==false) return false;
                //result =result & false;
            }
            
            else if(rec_visited[u]==true)
            {
                visited[u]=-1;
                result = false;
            }
            
            if(visited[u]==-1)
            {
                result = false;
            }
        }
        
        rec_visited[s] = false;
        
        if(result==false)
            visited[s] = -1;
       // res.push_back(s);
        //return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
               adj[i].push_back(graph[i][j]);        
            }
        }
        
        
        vector<int>visited(n,0);
        
        
        
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            vector<int>rec_visited(n,0);
            if(visited[i]!=0) continue;
            
            dfs(i,adj,visited,rec_visited,res);
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]!=-1)
                res.push_back(i);
        }
        return res;
    }
};
