class Solution {
public:
    
    int find(int i,vector<int>&parent)
    {
        if(parent[i]==-1)
            return i;
        
        return parent[i] = find(parent[i],parent);
    } 
    
    void unite(int n1,int n2,vector<int>&parent,vector<int>&rank)
    {
        int par1 = find(n1,parent);
        int par2 = find(n2,parent);
        
        if(par1!=par2)
        {
            if(rank[par1]>=rank[par2])
            {
                rank[par1] += rank[par2];
                parent[par2] = par1;
            }
            
            else{
                rank[par2] += rank[par1];
                parent[par1] = par2;
            }
        }
        
    }
    
    bool equationsPossible(vector<string>& equations) {
      vector<int>parent(26,-1);
        
      vector<int>rank(26,1);
        
        int n = equations.size();
 
        
        // first checking for all == expressions and if we get then we 
        // will unite the both variable together
        for(int i=0;i<n;i++)
        {
            char a = equations[i][0];
            char b = equations[i][1];
            char c = equations[i][2];
            char d = equations[i][3];
            
            int ch1 = a - 'a';
            int ch2 = d - 'a';
            
            
            if(b == '=')
            {
                 unite(ch1,ch2,parent,rank); 
            }
            
            
        }
        
        // In this we will be checking all != expressions and if we get
        // then we will check parents of both variables and if they
        // have same parents then we will return false because
        // we cannot have a==b and a!=b at same time
        
        for(int i=0;i<n;i++)
        {
            char a = equations[i][0];
            char b = equations[i][1];
            char c = equations[i][2];
            char d = equations[i][3];
            
            int ch1 = a - 'a';
            int ch2 = d - 'a';
            
            
            if(b == '!')
            {
              
                int par1 = find(ch1,parent);
                int par2 = find(ch2,parent);
                
                cout<<par1<<" "<<par2;
                if(par1 == par2) return false;
            }
            
        }
        
        
        // if everything goes good we return true
        return true;
        
    }
};
