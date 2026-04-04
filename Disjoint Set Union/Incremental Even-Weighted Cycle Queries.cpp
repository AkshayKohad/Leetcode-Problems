class Solution {
public:
    int find(int par,vector<int>&parent,vector<int>&parity){
        if(parent[par]==-1)return par;

        int org_parent = parent[par];
        parent[par] = find(parent[par],parent,parity);

        parity[par] ^= parity[org_parent];

        return parent[par];
    }

    int unite(int u,int v,int w,vector<int>&parity,vector<int>&parent,vector<int>&rank){
        int pu = find(u,parent,parity);
        int pv = find(v,parent,parity);

        if(pu == pv){
            if(parity[u]^parity[v]^w == 0)return true;
            return false;
        }

        if(rank[pu]>=rank[pv]){
            parent[pv] = pu;
            parity[pv] = parity[u]^parity[v]^w;
            rank[pu] += rank[pv];
        }else{
            parent[pu] = pv;
            parity[pu] = parity[u]^parity[v]^w;
            rank[pv] += rank[pu];
        }

        return true;
    }
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        vector<int>parity(n,0);

        int result = 0;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(unite(u,v,w,parity,parent,rank)) result++;
        }

        return result;
        
    }
};
