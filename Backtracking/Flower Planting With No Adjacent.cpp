class Solution {
public:
    
    
    bool isSafe(int node,vector<int>adj[],vector<int>&flower,int f)
    {
        for(auto u : adj[node])
        {
            if(flower[u] == f)
                return false;
        }
        
        
        return true;
    }
    bool solve(int i,int n,vector<int>adj[],vector<int>&flower)
    {
        if(i==n)
        {
            return true;
        }
        
        for(int j=1;j<=4;j++)
        {
            if(isSafe(i,adj,flower,j))
            {
                flower[i] = j;
                
                if(solve(i+1,n,adj,flower))return true;
                
                flower[i] = 0;
            }
        }
        
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int>adj[n];
        
        for(int i=0;i<paths.size();i++)
        {
            int x = paths[i][0]-1;
            int y = paths[i][1]-1;
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            
        }
        
        vector<int>flower(n,0);
        
        solve(0,n,adj,flower);
        
        return  flower;
    }
};
