
//Binary Lifting

class TreeAncestor {
public:
    
    vector<vector<int>>states;
    TreeAncestor(int n, vector<int>& parent) {
        
        // till 2^20
        states.resize(20,vector<int>(n,-1));
        
         // 2^0
        for(int i=0;i<n;i++)
        {
            states[0][i] = parent[i];
        }
        
        // 2^i
        
        for(int i=1;i<20;i++)
        {
            for(int node=0;node<n;node++)
            {
                int nodep = states[i-1][node];
                
                if(nodep!=-1)
                {
                    states[i][node] = states[i-1][nodep];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=0;i<20;i++)
        {
            if(k & (1<<i))
            {
                node = states[i][node];
                
                if(node==-1) return -1;
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
