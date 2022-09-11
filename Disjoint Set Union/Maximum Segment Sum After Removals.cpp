// Same Question as Destroying Array in Codeforces




class Solution {
public:
    
    int find(int i,vector<int>&parent)
    {
        if(parent[i]==-1)
            return i;
        
        
        return parent[i] = find(parent[i],parent);
    }
    
    
    void unite(int n1,int n2,vector<int>&parent,vector<long long>&rank)
    {
        int parent1 = find(n1,parent);
        
        int parent2 = find(n2,parent);
        
        if(parent1!=parent2)
        {
            if(rank[parent1]>=rank[parent2])
            {
              parent[parent2] = parent1;
                
              rank[parent1] += rank[parent2];  
            }
            
            else{
                parent[parent1] = parent2;
                
                rank[parent2] += rank[parent1];
                
            }
        }
            
    }
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        
        
        int n = nums.size();
        vector<long long>ans;
        
        ans.push_back(0);
        
        
        vector<int>parent(n,-1);
        
        vector<long long>rank(n);
        
        for(int i=0;i<n;i++)
        {
            rank[i] = nums[i];
        }
        
        
        vector<int>state(n,0);
        
        long long maxi = 0;
        for(int i=n-1;i>=0;i--)
        {
            int index = removeQueries[i];

            state[index] = 1;
            
             if(index-1>=0 && state[index-1]==1)
             {
                 unite(index-1,index,parent,rank);
             }
            
            
             if(index+1<n && state[index+1]==1)
             {
                 unite(index+1,index,parent,rank);
             }
            
            int par = find(index,parent);
            
            
            
            if(maxi<rank[par])
                maxi = rank[par];
            
            //maxi = max(maxi,rank[par]);
            
            ans.push_back(maxi);
        }
        
        // this is full sum, we don't want that in answer so we pop it
        
        ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};
