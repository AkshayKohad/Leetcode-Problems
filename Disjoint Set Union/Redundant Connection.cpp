class Solution {
public:
    
    int find(int i,vector<int>&parent)
    {
        if(parent[i]==-1)
            return i;
        
        return parent[i] = find(parent[i],parent);
    }
    
    
    void unite(int x,int y,vector<int>&parent,vector<int>&rank,bool &flag)
    {
        int s1 = find(x,parent);
        
        int s2 = find(y,parent);
        
        if(s1!=s2)
        {
            if(rank[s1]>rank[s2])
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            
            else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
        }
        
        else{
            flag=true;
        }
        
       
    }
  
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>a;
        
        
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        
        for(int i=0;i<edges.size();i++)
        {
            bool flag = false;
            int x = edges[i][0];
            int y = edges[i][1];
            
           unite(x-1,y-1,parent,rank,flag);
             if(flag==true)
             {
                 a = edges[i];
                 break;
             }
        }
        
        return a;
    }
};
