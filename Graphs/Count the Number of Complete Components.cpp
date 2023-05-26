class Solution {
public:
    
    void dfs(int nd,vector<int>&visited,vector<int>adj[],vector<int>&list)
    {
        list.push_back(nd);
        visited[nd]=1;
        for(auto u:adj[nd])
        {
            if(visited[u]==1)
                continue;
            
            dfs(u,visited,adj,list);
            
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
     
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            
        }
        
        vector<int>visited(n,0);
        
        int result = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
                continue;
            
            vector<int>list;
            
            dfs(i,visited,adj,list);
            
            int total_nodes = list.size();
            
            
            
            int total_edges = total_nodes*(total_nodes-1)/2;
            
            
            
            int count_edges = 0;
            
            for(int j=0;j<list.size();j++)
            {
                count_edges += adj[list[j]].size();
            }
            count_edges = count_edges/2;
           
            if(count_edges == total_edges)
                result++;
        }
        
        return result;
    }
};
