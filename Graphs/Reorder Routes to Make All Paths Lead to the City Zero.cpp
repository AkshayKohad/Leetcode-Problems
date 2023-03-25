class Solution {
public:

    void dfs(int src,int par,vector<pair<int,int>>adj[],int &count)
    {
       for(auto u : adj[src])
       {
           if(u.first!=par)
           {
              if(u.second==1)
              {
                  count++;

              }
              dfs(u.first,src,adj,count);
           }
       }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<pair<int,int>>adj[n];

        for(int i=0;i<connections.size();i++)
        {
            int x = connections[i][0];
            int y = connections[i][1];

            adj[x].push_back({y,1});
            adj[y].push_back({x,-1});

        }
        int count = 0;
        dfs(0,-1,adj,count);

        return count;


    }
};
