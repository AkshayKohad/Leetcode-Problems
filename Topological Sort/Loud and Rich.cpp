class Solution {
public:
    int solve(int src,vector<int>adj[],vector<int>&quiet,vector<int>&result){
        if(result[src]!=-1)return result[src];
        int res_index = src;
        for(auto child : adj[src]){
            int ind = solve(child,adj,quiet,result);
            if(quiet[res_index]>quiet[ind]){
                res_index = ind;
            }
        }
        return result[src] = res_index;

    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        vector<int>result(n,-1);
        vector<int>adj[n];
        for(auto rich : richer){
            int a = rich[0];
            int b = rich[1];
            adj[b].push_back(a);
        }

        
        for(int i=0;i<n;i++){
            if(result[i]!=-1)continue;
            solve(i,adj,quiet,result);
        }
        return result;
    }
};
