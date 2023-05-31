class Solution {
public:
    
    void dfs(int node,vector<int>adj[],vector<int>&visited,int &count)
    {
        visited[node] = 1;
        count++;
        
        for(auto adj_nd : adj[node])
        {
            if(visited[adj_nd] == 1) continue;
            
            dfs(adj_nd,adj,visited,count);
        }
    }
    
    
    vector<int>prime_factorization(int val)
    {
        vector<int>result;
        
        if(val%2==0)
        {
            result.push_back(2);
            while(val%2==0)
                val = val/2;
        }
        
        for(int i=3;i<=sqrt(val);i=i+2)
        {
            if(val%i==0)
            {
                result.push_back(i);
                
                while(val%i==0)
                    val = val/i;
            }
        }
        
        if(val>2)
            result.push_back(val);
        
        return result;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        
      
        
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            
          vector<int>prime_factors = prime_factorization(nums[i]);
            
            for(int j=0;j<prime_factors.size();j++)
            {
              
                mp[prime_factors[j]].push_back(i);
            }
         
        }
        int n = nums.size();
        
        vector<int>adj[n];
        map<int,unordered_set<int>>m;
        for(auto prime : mp)
        {
            int prime_num = prime.first;
            //cout<<prime_num<<endl;
            vector<int>nodes = prime.second;
            
            if(nodes.size()<=1)
                continue;
            
            for(int j=1;j<nodes.size();j++)
            {
                
                int x = nodes[j-1];
                int y = nodes[j];
                
               
                
                
                    adj[x].push_back(y);
                   
                
                    adj[y].push_back(x);
                 
            }
         
        }
        
        vector<int>visited(n,0);
        int count = 0;
        
        dfs(0,adj,visited,count);
        
       
        if(count==n)
            return true;
        
        return false;
        
        
    }
};
