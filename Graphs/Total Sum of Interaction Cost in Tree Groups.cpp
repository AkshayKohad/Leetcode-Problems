class Solution {
public:
    long long solve(int src,vector<int>adj[],vector<int>&visited,int &grp_num,int &grp_sz,vector<int>&group,long long &result){
        visited[src] = 1;
        long long total_nd = 0;
        for(auto child : adj[src]){
            if(visited[child])continue;

            long long cnt_nd = solve(child,adj,visited,grp_num,grp_sz,group,result);
            result += (grp_sz-cnt_nd)*(cnt_nd);
            total_nd += cnt_nd;
        }

        if(group[src] == grp_num)return total_nd+1;

        return total_nd;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<int>adj[n];
        for(auto edge : edges){
            int x = edge[0];
            int y = edge[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        unordered_map<int,int>group_cnt;
        for(auto grp : group){
            group_cnt[grp]++;
        }
        long long result = 0;

        for(auto res : group_cnt){
            if(res.second == 1){
                continue;
            }
            int grp_num = res.first;
            int grp_sz  = res.second;
            vector<int>visited(n,0);
            solve(0,adj,visited,grp_num,grp_sz,group,result);
        } 
        return result;
    }
};
