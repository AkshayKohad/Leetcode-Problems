class Solution {
public:
    
    int find(int i,int parent[])
    {
        if(parent[i]==-1)
            return i;
        
        return parent[i] = find(parent[i],parent);
    }
    void unite(int x,int y,int rank[],int parent[])
    {
        int s1 = find(x,parent);
        int s2 = find(y,parent);
        
        if(s1!=s2)
        {
            if(rank[s1]>=rank[s2])
            {
                parent[s2] = s1;
                rank[s1] +=rank[s2];
            }
            
            else{
                
                parent[s1] = s2;
                rank[s2] +=rank[s1];
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<pair<int,int>>edges;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<j)
                {
                    if(isConnected[i][j]==1)
                    {
                        edges.push_back({i,j});
                    }
                }
            }
        }
        
        
        int parent[n];
        int rank[n];
        
        for(int i=0;i<n;i++)
        {
           parent[i]=-1;
            rank[i]=1;
        }
        
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i].first;
            int y = edges[i].second;
            
            
            if(parent[x]!=parent[y])
            {
             unite(x,y,rank,parent);   
            }
            
            else if(parent[x]== parent[y] && parent[x]==-1)
            {
                unite(x,y,rank,parent);
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                count++;
        }
        
        return count;
    }
};
