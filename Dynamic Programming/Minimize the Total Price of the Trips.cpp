class Solution {
public:
    
    void find_path(int node,int dest,vector<int>adj[],vector<int>&occurences_in_trips,int par,vector<int>&path)
    {
        path.push_back(node);
        if(node==dest)
        {
            
            for(auto nd : path)
            {
                occurences_in_trips[nd]++;
            }
            
            path.pop_back();
            
            return;
            
        }
        
        for(auto adj_nd : adj[node])
        {
            if(adj_nd == par) continue;
             
            find_path(adj_nd,dest,adj,occurences_in_trips,node,path);
            
        }
        
        path.pop_back();
    }
    
    int solve(int node,int set_half,vector<int>&occurences_in_trips,vector<int>adj[],vector<int>&price,int par,vector<vector<int>>&memo)
    {
        
        if(memo[node][set_half]!=-1)
            return memo[node][set_half];
        
        int res1 = INT_MAX;
        int res2 = INT_MAX;
        
        if(set_half==0)
        {
            res1 = occurences_in_trips[node]*price[node]/2;
            
            for(auto adj_nd : adj[node])
            {
                if(adj_nd == par)
                    continue;
                
                res1 += solve(adj_nd,1,occurences_in_trips,adj,price,node,memo);
            }
            
             res2 = occurences_in_trips[node]*price[node];
            
            for(auto adj_nd : adj[node])
            {
                if(adj_nd == par)
                    continue;
                
                res2 += solve(adj_nd,0,occurences_in_trips,adj,price,node,memo);
            }
        }
        
        else{
            
            res2 = occurences_in_trips[node]*price[node];
            
            for(auto adj_nd : adj[node])
            {
                if(adj_nd == par)
                    continue;
                
                res2 += solve(adj_nd,0,occurences_in_trips,adj,price,node,memo);
            }
        }
        
        return memo[node][set_half] = min(res1,res2);
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
     
        
        
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        
        vector<int>occurences_in_trips(n,0);
        for(int i=0;i<trips.size();i++)
        {
            int start = trips[i][0];
            int end = trips[i][1];
            
            vector<int>path;
            find_path(start,end,adj,occurences_in_trips,-1,path);
        }
        
        
        vector<vector<int>>memo(n,vector<int>(2,-1));
        
        return solve(0,0,occurences_in_trips,adj,price,-1,memo);
    }
};
