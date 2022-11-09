class Solution {
public:
    
    #define ll long long 
    
    ll maximum = 100000000007;
        
    void dijkstra(vector<pair<ll,ll>>adj[],vector<pair<ll,ll>>adj_rev[],int &n,vector<ll>&dist,ll src,int rev)
    {
           dist[src] = 0;
        
        
     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
     
        pq.push({0,src});
        
        while(pq.size()>0)
        {
            pair<ll,ll>cur = pq.top();
            
            pq.pop();
            
            ll distance = cur.first;
            ll node = cur.second;
            
            // TLE Elimination
            if(distance > dist[node])
                continue;
            
            
            if(rev==0)
            {
                
            for(auto k:adj[node])
            {
                ll neigh = k.first;
                ll neigh_distance = k.second;
                
                if(dist[neigh] > distance + neigh_distance)
                {
                  dist[neigh] = distance + neigh_distance;
                    
                  pq.push({dist[neigh],neigh});  
                }
            }
                
            }
            
            else if(rev==1)
            {
               for(auto k:adj_rev[node])
               {
                ll neigh = k.first;
                ll neigh_distance = k.second;
                
                if(dist[neigh] > distance + neigh_distance)
                {
                  dist[neigh] = distance + neigh_distance;
                    
                  pq.push({dist[neigh],neigh});  
                }
                   
               } 
                
            }
            
        }
        
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        
        vector<ll>dist_src1(n,maximum);
        vector<ll>dist_src2(n,maximum);
        vector<ll>dist_dest(n,maximum);
        
        vector<pair<ll,ll>>adj[n];
        vector<pair<ll,ll>>adj_rev[n];
        
        for(int i=0;i<edges.size();i++)
        {
            ll from = edges[i][0];
            ll to = edges[i][1];
            ll w = edges[i][2];
            
            adj[from].push_back({to,w});
            adj_rev[to].push_back({from,w});
        }
        
        dijkstra(adj,adj_rev,n,dist_src1,src1,0);
        
        dijkstra(adj,adj_rev,n,dist_src2,src2,0);
        
        dijkstra(adj,adj_rev,n,dist_dest,dest,1);
        
        
        ll result = maximum;
        
        for(int i=0;i<n;i++)
        {
            if(dist_src1[i]==maximum || dist_src2[i]==maximum || dist_dest[i]==maximum)
                continue;
            
            result = min(result,dist_src1[i]+dist_src2[i]+dist_dest[i]);
        }
        
        if(result==maximum)
            return -1;
        
        return result;
        
    }
    
};
