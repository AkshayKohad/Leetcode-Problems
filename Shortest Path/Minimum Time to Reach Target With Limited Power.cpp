class Solution {
public:
    #define ll long long
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        
        vector<pair<int,int>>adj[n];
        for(auto edge : edges){
            int src = edge[0];
            int dest =  edge[1];
            int ti = edge[2];

            adj[src].push_back({dest,ti});
        }

        vector<vector<ll>>dist(n,vector<ll>(power+1,LLONG_MAX));

        priority_queue<vector<ll>>pq;
        pq.push({0,power,source});

        while(pq.size()>0){
            vector<ll>cur = pq.top();
            pq.pop();

            ll cur_time = -cur[0];
            ll cur_power = cur[1];
            ll cur_nd = cur[2];

            if(cur_nd == target) return {cur_time,cur_power};

            if(dist[cur_nd][cur_power] < cur_time)continue;
            
            if(cur_power < cost[cur_nd])continue;

            for(auto adj_nd : adj[cur_nd]){
                int dest_nd = adj_nd.first;
                int req_time = adj_nd.second;

                if(dist[dest_nd][cur_power - cost[cur_nd]] > cur_time + req_time){
                    dist[dest_nd][cur_power - cost[cur_nd]] = cur_time + req_time;
                    pq.push({-dist[dest_nd][cur_power-cost[cur_nd]],cur_power-cost[cur_nd],dest_nd});
                }
            }
        }

        return {-1,-1};
    }
};
