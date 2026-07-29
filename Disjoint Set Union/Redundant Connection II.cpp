class Solution {
public:
    int find(vector<int>&parent,int par){
        if(parent[par]==-1)return par;
        return parent[par] = find(parent,parent[par]);
    }
    bool unite(int nd1,int nd2,vector<int>&parent,vector<int>&rank){
        int par1 = find(parent,nd1);
        int par2 = find(parent,nd2);
        
        if(par1 == par2)return true;

        if(rank[par1] >= rank[par2]){
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }else{
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
        return false;
    }

    bool cycle_found(vector<vector<int>>&edges,vector<int>&extra_edge){
        int n = edges.size();
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        for(auto edge : edges){
            if(edge == extra_edge)continue;
            int src = edge[0];
            int dest = edge[1];

            if(unite(src-1,dest-1,parent,rank))return true;
        }
        return false;
    }

    vector<int>find_edge(vector<vector<int>>&edges){
        int n = edges.size();
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        for(auto edge : edges){
            int src = edge[0];
            int dest = edge[1];

            if(unite(src-1,dest-1,parent,rank))return {src,dest};
        }
        return {-1,-1};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        vector<int>extra_edge;
        vector<int>cur_edge;
        int n = edges.size();
        vector<int>edge_parents(n,-1);

        for(auto edge : edges){
            int src = edge[0]-1;
            int dest = edge[1]-1;
            if(edge_parents[dest]!=-1){
                extra_edge = edge;
                cur_edge = {edge_parents[dest]+1,dest+1};
            }
            edge_parents[dest] = src;
        }

        if(extra_edge.size()==0){
            return find_edge(edges);
        }else{
            if(cycle_found(edges,extra_edge)){
                return cur_edge;
            }else{
                return extra_edge;
            }
        }
    }
};

// No two parents(will have cycle then)
// Two parent, with cycle
// Two parents, no cycle
