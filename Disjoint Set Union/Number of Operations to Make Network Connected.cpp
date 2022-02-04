class Solution {
public:
    
    int find(int i,vector<int>&parent)
    {
        if(parent[i]==-1)
            return i;
        
        return parent[i] = find(parent[i],parent);
    }
    
    void unite(int x,int y,vector<int>&parent,vector<int>&rank,int &count_cycles)
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
            count_cycles++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n,-1);
        vector<int>rank(n,1);
        
        int count_cycles=0;
        for(int i=0;i<connections.size();i++)
        {
            int x = connections[i][0];
            int y = connections[i][1];
            unite(x,y,parent,rank,count_cycles);
        }
        cout<<count_cycles<<endl;
        int count_networks = 0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                count_networks++;
            cout<<parent[i]<<" ";
        }
        
        cout<<endl;
        
        for(int i=0;i<n;i++)
        {
         cout<<rank[i]<<" ";   
        }
        
        if(count_cycles<count_networks-1)
        return -1;
        
       
            return count_networks-1;
        
    }
};
