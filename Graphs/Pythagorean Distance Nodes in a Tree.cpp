class Solution {
public:

    void find_distance(int src,vector<int>adj[],vector<int>&dist,int distance){
        dist[src] = distance;

        for(auto u : adj[src]){
            if(dist[u]<=distance+1)continue;

            find_distance(u,adj,dist,distance+1);
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        
        vector<int>adj[n];

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int>distx(n,INT_MAX);
        vector<int>disty(n,INT_MAX);
        vector<int>distz(n,INT_MAX);

        find_distance(x,adj,distx,0);
        find_distance(y,adj,disty,0);
        find_distance(z,adj,distz,0);

        int result = 0;

        for(int i=0;i<n;i++){
            long long dx = distx[i];
            long long dy = disty[i];
            long long dz = distz[i];

            long long sq_dx = dx*dx;
            long long sq_dy = dy*dy;
            long long sq_dz = dz*dz;

            if((sq_dx + sq_dy == sq_dz) || (sq_dz + sq_dy == sq_dx) || (sq_dx + sq_dz == sq_dy))result++;
        }

        return result;
    }
};
