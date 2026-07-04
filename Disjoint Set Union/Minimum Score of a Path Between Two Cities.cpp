class Solution {
public:
    int find(int par,vector<int>&parent){
        if(parent[par] == -1)return par;
        return parent[par] = find(parent[par],parent);
    }

    void unite(int x1,int x2,vector<int>&parent,vector<int>&rank){
        int par1 = find(x1,parent);
        int par2 = find(x2,parent);

        if(par1 == par2)return;
        if(rank[par1]>=rank[par2]){
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }else{
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
     vector<int>res_minimum(n+1,INT_MAX);
     vector<int>parent(n+1,-1);
     vector<int>rank(n+1,1);
     for(auto road : roads){
        int loc1 = road[0];
        int loc2 = road[1];
        int dist = road[2];
        res_minimum[loc1] = min(res_minimum[loc1],dist);
        res_minimum[loc2] = min(res_minimum[loc2],dist);
        unite(loc1,loc2,parent,rank);
     }
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<=n;i++){
        cout<<res_minimum[i]<<" ";
    }
    cout<<endl;
     int par_src = find(1,parent);
     int par_dest = find(n,parent);
     if(par_src != par_dest)return -1;
     int result = INT_MAX;
     for(int i=1;i<=n;i++){
        if(find(i,parent) == par_src)result = min(result,res_minimum[i]);
     }
     return result;   
    }
};
