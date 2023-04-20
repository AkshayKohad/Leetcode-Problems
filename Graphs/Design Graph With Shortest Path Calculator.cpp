class Graph {
public:
    int n;
   
    vector<pair<int,int>>adj[100];
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        
        for(int i=0;i<edges.size();i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int dist = edges[i][2];
            
            adj[from].push_back({to,dist});
            
        }
        
    }
    
    void addEdge(vector<int> edge) {
        
            int from = edge[0];
            int to = edge[1];
            int dist = edge[2];
            
            adj[from].push_back({to,dist});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(n,INT_MAX);
        
        dist[node1] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,node1});
        
        while(pq.size()>0)
        {
            pair<int,int>cur = pq.top();
            pq.pop();
            
            int distance = cur.first;
            int nd = cur.second;
            
            for(auto node : adj[nd])
            {
                int adj_nd = node.first;
                int adj_distance = node.second;
                
                if(distance+adj_distance < dist[adj_nd])
                {
                    dist[adj_nd] = distance+adj_distance;
                    
                    pq.push({dist[adj_nd],adj_nd});
                }
                
                
            }
        }
        
        if(dist[node2]==INT_MAX)
            return -1;
        
        return dist[node2];
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
