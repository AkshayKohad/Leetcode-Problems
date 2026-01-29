class Solution {
public:
    void djikstra(vector<int>&visited,int src,vector<pair<int,int>>adj[]){
        visited[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,src});

        while(pq.size()>0){
            pair<int,int>cur = pq.top();
            pq.pop();

            int cur_nd = cur.second;
            int nd_dist = cur.first;

            for(auto adj_nd : adj[cur_nd]){
                pair<int,int>nd = adj_nd;

                int neigh_nd = nd.first;
                int adj_dist = nd.second;

                if(visited[neigh_nd]==-1 || visited[neigh_nd] > visited[cur_nd]+adj_dist){
                    visited[neigh_nd] = visited[cur_nd]+adj_dist;
                    pq.push({visited[neigh_nd],neigh_nd});
                }

            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<pair<char,char>,int>mp;
        int m = original.size();
        for(int i=0;i<m;i++){
            char ch_og = original[i];
            char ch_chg = changed[i];
            if(mp.find({ch_og,ch_chg})==mp.end()){
                mp[{ch_og,ch_chg}] = cost[i];
            }else{
                mp[{ch_og,ch_chg}] = min(cost[i],mp[{ch_og,ch_chg}]);
            }
        }

        vector<pair<int,int>>adj[26];
        for(auto val : mp){
            pair<char,char>cur = val.first;
            int cst = val.second;

            int start = cur.first - 'a';
            int dest = cur.second - 'a';

            adj[start].push_back({dest,cst});
        }

        vector<vector<int>>visited(26,vector<int>(26,-1));

        for(int i=0;i<26;i++){
            djikstra(visited[i],i,adj);
        }


        long long result = 0;
        int n = source.length();
        for(int i=0;i<n;i++){
            if(source[i]==target[i])continue;

            int src_ch = source[i]-'a';
            int tar_ch = target[i]-'a';

            if(visited[src_ch][tar_ch]==-1)return -1;

            result += (long long)visited[src_ch][tar_ch];
        }

        return result;
    }
};
