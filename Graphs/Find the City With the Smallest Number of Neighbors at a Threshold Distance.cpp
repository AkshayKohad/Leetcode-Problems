class Solution {
public:
    
    int djisktra(int src,vector<pair<int,int>>adj[],int n,int distanceThreshold)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,src});
        
        vector<int>dist(n,INT_MAX);
        
        dist[src] = 0;
        
        while(pq.size()>0)
        {
            pair<int,int>cur = pq.top();
            pq.pop();
            
            int cur_dist = cur.first;
            int node = cur.second;
            
            
            for(auto neigh : adj[node])
            {
                int neigh_node = neigh.first;
                int neigh_dist = neigh.second;
                
                if(cur_dist+neigh_dist <dist[neigh_node])
                {
                      dist[neigh_node] = cur_dist+neigh_dist;
                    
                    pq.push({cur_dist+neigh_dist,neigh_node});
                }
                
                
                
            }
        }
        
       // cout<<src<<"-> ";
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<=distanceThreshold)
            {
               // cout<<i<<" ";
                ans++;
            }
        }
        //cout<<endl;
        return ans-1;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
         vector<pair<int,int>>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            
            adj[from].push_back({to,weight});
            adj[to].push_back({from,weight});    
        }
        
        int node_no = -1;
        int res  = n+1;
        for(int i=0;i<n;i++)
        {
            int ans = djisktra(i,adj,n,distanceThreshold);
            
            
            if(res>ans)
            {
                res = ans;
                node_no = i;
            }
            
            else if(res==ans)
            {
                 node_no = max(node_no,i);
            }
            
        }
        return node_no;
    }
};
