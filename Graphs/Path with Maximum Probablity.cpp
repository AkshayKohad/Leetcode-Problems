// Using Dijkstra's Algorithm

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        priority_queue<pair<double,int>>pq;
        
        vector<double>dist(n,0.0);
        
        vector<pair<double,int>>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            
            double wt = succProb[i];
            
            adj[x].push_back({wt,y});
            adj[y].push_back({wt,x});
            
        }
        
        dist[start] = 1.0;
        pq.push({1.0,start});
        
        while(pq.empty()==false)
        {
           double d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            for(auto nd : adj[node])
            {
                double distance = nd.first;
                int neighbour = nd.second;
                
                if(dist[neighbour]<dist[node]*distance)
                {
                    dist[neighbour] = dist[node]*distance;
                    
                    pq.push({dist[neighbour],neighbour});
                }
            }
         
        }
        
        
      
        return dist[end];
    }
};
