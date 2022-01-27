class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,int src,int parent,vector<int>&visited,int color)
    {
        visited[src]=color;
        for(auto x : graph[src])
        {
            if(visited[x]==0)
            {
                bool res = dfs(graph,x,src,visited,3-color);
                if(res==false)
                    return false;
            }
            
            else{
                if(x!=parent)
                {
                    if(visited[x]==visited[src])
                        return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
              
                if( dfs(graph,i,-1,visited,1)==false)
                    return false;
            }
        }
        return true;
    }
};
