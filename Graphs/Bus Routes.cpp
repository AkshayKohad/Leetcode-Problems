class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target)return 0;

        int n = routes.size();

        vector<int>visited(n,0);

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                 mp[routes[i][j]].push_back(i);
            }
        }


      queue<pair<int,int>>q;
        for(auto k:mp[source])
        {
            visited[k] = 1;
            q.push({k,1});
        }

        while(q.empty()==false)
        {
            pair<int,int>cur = q.front();
            q.pop();
            int route_number = cur.first;
            int bus_no = cur.second;

            for(auto k:routes[route_number])
            {
                if(k==target) return bus_no;

                for(auto u:mp[k])
                {
                    if(visited[u]==0)
                    {
                        visited[u] = 1;
                        q.push({u,bus_no+1});
                    }
                }
            }
        }

    return -1;
    }
};
