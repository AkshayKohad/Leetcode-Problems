// BFS + Bit manipulation


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        if(n==1) return 0;
        
        queue<pair<int,int>>q;
        
        int finalstate = (1<<n)-1;
        
        vector<vector<int>>visited(n,vector<int>(finalstate,0));
        
        
        for(int i=0;i<n;i++)
        {
            q.push({i,(1<<i)});
        }
        
        int res = 0;
        
        while(q.empty()==false)
        {
            int sz = q.size();
            res++;
            while(sz--)
            {
                pair<int,int>curr = q.front();
                q.pop();
                
                int node = curr.first;
                
                int state = curr.second;
                
                for(auto neighbour :graph[node])
                {
                    int newstate = state | (1<<neighbour);
                
                    
                    if(newstate == finalstate) return res;
                    
                    if(visited[neighbour][newstate]==1) continue;
                    
                    q.push({neighbour,newstate});
                    visited[neighbour][newstate] = 1;
                }
            }
        }
        return -1;
    }
};
