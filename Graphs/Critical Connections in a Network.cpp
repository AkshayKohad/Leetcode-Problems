class Solution {
public:
    
    void solve(int cur,int par,vector<int>&discover,vector<int>&lowest,int &timer, vector<int>adj[], vector<vector<int>>&ans)
    {
        discover[cur] = lowest[cur] = timer++;
        
        for(auto child : adj[cur])
        {
            if(discover[child]==0)
            {
                solve(child,cur,discover,lowest,timer,adj,ans);
                
                lowest[cur] = min(lowest[cur],lowest[child]);
                
                if(lowest[child] > discover[cur])
                {
                    ans.push_back({cur,child});
                }
            }
            
            else if(par!=child){
                //backedge cycle found
                
                lowest[cur] = min(lowest[cur],discover[child]);
            }
        }
    }
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>discover(n,0);
        vector<int>lowest(n,0);
        int timer = 1;
        
        vector<int>adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int>>ans;
        solve(0,-1,discover,lowest,timer,adj,ans);
        
        return ans;
    }
};
