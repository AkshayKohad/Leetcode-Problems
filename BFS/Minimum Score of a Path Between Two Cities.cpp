class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(auto road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        vector<int>visited(n+1,0);
        queue<int>q;
        q.push(1);
        visited[1] = 1;
        int result = INT_MAX;
        while(q.empty()==false){
            int cur = q.front();
            q.pop();
           

            for(auto adj_nd : adj[cur]){
                int nd = adj_nd.first;
                int val = adj_nd.second;
                result = min(result,val);

                if(visited[nd])continue;
                q.push(nd);
                visited[nd] = 1;
            }
        }

        return result;
    }
};
