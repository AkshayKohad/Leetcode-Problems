class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<times.size();i++)
        {
            int src = times[i][0]-1;
            int dest = times[i][1]-1;
            int w = times[i][2];
            
            adj[src].push_back({dest,w});
        }
        
        
       queue<pair<int,int>>q;
        vector<bool>visited(n);
        
        vector<int>time_val(n,INT_MAX);
        
        q.push({k-1,0});
        visited[k-1]=true;
        time_val[k-1]=0;
        while(q.empty()==false)
        {
            pair<int,int>cur = q.front();
            q.pop();
            int u = cur.first;
            int t = cur.second;
            
            for(auto nd : adj[u])
            {
                
                int d = nd.first;
                int ti = nd.second;
                
                
                 visited[d] = true;
                
                if(time_val[d]<=t+ti)
                    continue;
                
               
                
                time_val[d] = min(time_val[d],t+ti);
                
                q.push({d,time_val[d]});
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
                return -1;
        }
        
        int res = time_val[0];
        for(int i=0;i<n;i++)
        {
            res = max(time_val[i],res);
        }
        
        return res;
    }
};
