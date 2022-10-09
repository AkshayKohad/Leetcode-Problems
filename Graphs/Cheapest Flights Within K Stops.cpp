class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<flights.size();i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int w = flights[i][2];
            
            adj[from].push_back({to,w});
        }
        
        
        queue<pair<int,pair<int,int>>>q;
        
        // {steps,{node,distance}}
        q.push({0,{src,0}});
            
        vector<int>dist(n,INT_MAX);    
        
        
        dist[src] = 0;
        
        while(q.empty()==false)
        {
            auto cur = q.front();
            q.pop();
            
            int steps = cur.first;
            int node = cur.second.first;
            int cur_dist = cur.second.second;
            
            
            if(steps>k) continue;
            
            for(auto neighbour : adj[node])
            {
                int neigh_node = neighbour.first;
                
                int neigh_dist = neighbour.second;
                
                if(dist[neigh_node] > cur_dist + neigh_dist && steps<=k)
                {
                    dist[neigh_node] = cur_dist + neigh_dist;
                    
                    q.push({steps+1,{neigh_node,cur_dist+neigh_dist}});
                }
                
                
            }
        }
            
            
        if(dist[dst]==INT_MAX)
            return -1;
        
        return dist[dst];
        
    }
};
