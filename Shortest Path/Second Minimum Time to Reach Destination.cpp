class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n];
        for(auto edge : edges){
            int src = edge[0];
            int dest = edge[1];
            adj[src-1].push_back(dest-1);
            adj[dest-1].push_back(src-1);
        }

        vector<int>dist(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            pair<int,int>cur = q.front();
            q.pop();
            int cur_nd = cur.first;
            int cur_time = cur.second;
            int val = cur_time/change;
            if(val%2){
                cur_time += change - cur_time%change;
            }

            for(auto nd : adj[cur_nd]){
                int next_time = cur_time + time;
                if(next_time == dist[nd])continue;
                if(next_time > dist[nd] && next_time >= dist2[nd])continue;

                if(next_time<dist[nd]){
                    int temp_time = dist[nd];
                    dist[nd] = next_time;
                    dist2[nd] = temp_time;
                }else if(next_time<dist2[nd]){
                    dist2[nd] = next_time;
                }
                q.push({nd,next_time});
            }
        }

        return dist2[n-1];
    }
};
