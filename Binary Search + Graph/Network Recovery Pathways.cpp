class Solution {
public:
    bool check(int limit,vector<pair<int,int>>adj[],vector<bool>&online,long long &k){
        int n = online.size();
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,-1);
        dist[0] = 0;
        pq.push({0,0});

        while(pq.size()>0){
            pair<long long,long long>cur = pq.top();
            pq.pop();

            long long src = cur.second;
            long long cur_dist = cur.first;
            
            if(dist[src] != -1 && cur_dist > dist[src])continue;

            if(src == n-1 && dist[n-1]<=k)return true;

            for(auto adj_nd : adj[src]){
                int nxt_nd = adj_nd.first;
                int cost = adj_nd.second;

                if(online[nxt_nd]==false || cost < limit)continue;

                if(cur_dist + (long long)cost > k)continue;

                if(dist[nxt_nd] == -1 || cur_dist + (long long)cost < dist[nxt_nd]){
                    dist[nxt_nd] = cur_dist + (long long)cost;
                    pq.push({dist[nxt_nd],nxt_nd});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<pair<int,int>>adj[n];
        set<int>st;
        for(auto edge : edges){
         adj[edge[0]].push_back({edge[1],edge[2]});
         st.insert(edge[2]);   
        }

        vector<int>cost;
        for(auto s : st){
            cost.push_back(s);
        }

        int l = 0;
        int r = cost.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = (r-l)/2 + l;

            if(check(cost[mid],adj,online,k)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans == -1 ? -1 : cost[ans];
    }
};
