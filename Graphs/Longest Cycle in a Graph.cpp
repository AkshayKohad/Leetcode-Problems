class Solution {
public:
    
    void solve(int src,vector<bool>&visited,vector<int>&rec_visited,vector<int>adj[],int count,int &res)
    {
        rec_visited[src] = count;
        visited[src] = true;
        
        
       
        
        
        for(auto u:adj[src])
        {
            
            if(visited[u]==false)
            {
                solve(u,visited,rec_visited,adj,count+1,res);
            }
            
            else{
                if(rec_visited[u]!=0)
                {
                    res = max(res,count-rec_visited[u]+1);
                }
            }
        }
        
        rec_visited[src] = 0;
        
    }
    int longestCycle(vector<int>& edges) {
     
        
        int n = edges.size();
       
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)
                continue;
            
            adj[i].push_back(edges[i]);
        }
        
        
        vector<bool>visited(n,false);
        
        vector<int>rec_visited(n,0);
        
        
        int res = -1;
        for(int i=0;i<n;i++)
        {
            
            if(visited[i]==false && edges[i]!=-1)
            {
                int count = 1;
                
                solve(i,visited,rec_visited,adj,count,res);
            }
        }
          
        
        return res;
        
    }
};
