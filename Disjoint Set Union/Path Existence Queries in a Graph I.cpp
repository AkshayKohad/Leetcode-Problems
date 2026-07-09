class Solution {
public:
    int find(int par,vector<int>&parent){
        if(parent[par] == -1)return par;

        return parent[par] = find(parent[par],parent);
    }
    void unite(int x1, int x2, vector<int>&parent, vector<int>&rank){
        int par1 = find(x1,parent);
        int par2 = find(x2,parent);

        if(par1 == par2)return;

        if(rank[par1] >= rank[par2]){
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }else{
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        vector<pair<int,int>>res_nums;
        for(int i=0;i<n;i++){
            res_nums.push_back({nums[i],i});
        }

        sort(res_nums.begin(),res_nums.end());

        for(int i=0;i<n-1;i++){
            int diff = res_nums[i+1].first - res_nums[i].first;

            if(diff <= maxDiff){
                unite(res_nums[i].second,res_nums[i+1].second,parent,rank);
            }
        }

        vector<bool>result;
        for(auto query : queries){
            int nd1 = query[0];
            int nd2 = query[1];

            int par1 = find(nd1,parent);
            int par2 = find(nd2,parent);

            if(par1 == par2){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }

        return result;
    }
};
