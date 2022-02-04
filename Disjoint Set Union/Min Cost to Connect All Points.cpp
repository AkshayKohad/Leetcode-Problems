class Solution {
public:
    
    int find(int i,int parent[])
    {
        if(parent[i]==-1)
        {
           return i;    
        }
        
        return parent[i] = find(parent[i],parent);
        
        
    }
    
    
    void unite(int x,int y,int parent[],int rank[])
    {
        int s1 = find(x,parent);
        int s2 = find(y,parent);
        
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<vector<int>>a;
        
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                
                a.push_back({dist,i,j});
            }
        }
        
        int v = points.size();
        int parent[v];
        int rank[v];
        
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        
        sort(a.begin(),a.end());
        int ans=0;
        for(auto edge:a)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            
            if(find(x,parent)!=find(y,parent))
            {
                unite(x,y,parent,rank);
                ans += w;
            }
            
            
        }
        
        return ans;
    }
};
