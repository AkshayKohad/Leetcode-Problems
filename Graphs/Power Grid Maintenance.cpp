class Solution {
public:
    void solve(int src,vector<int>adj[],vector<int>&visited,int &curId){
        visited[src] = curId;
        for(auto u : adj[src]){
            if(visited[u]!=0)continue;
            solve(u,adj,visited,curId);
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>adj[c+1];
        for(auto connection : connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        vector<int>visited(c+1,0);
        unordered_map<int,set<int>>mp;
        int curId = 1;
        vector<int>onlineStatus(c+1,1);

        for(int i=1;i<=c;i++){
            if(visited[i]!=0)continue;
            solve(i,adj,visited,curId);
            curId++;
        }

        for(int i=1;i<=c;i++)mp[visited[i]].insert(i);

        vector<int>results;
        for(auto query : queries){
            int type = query[0];
            int station = query[1];
            int gridId = visited[station];
            if(type == 1){
                
                if(mp[gridId].size()==0){
                    results.push_back(-1);
                }else{
                    if(onlineStatus[station]){
                        results.push_back(station);
                    }else{
                        int minId = *mp[gridId].begin();
                        results.push_back(minId);
                    }
                    
                }
            }else{
                if(onlineStatus[station]){
                    onlineStatus[station] = 0;
                    mp[gridId].erase(station);
                }
            }
        }

        return results;

    }
};
