class Solution {
public:
    
    
    void remove(vector<int>&cur,int &val)
    {
        for(int i=0;i<cur.size();i++)
        {
            int bit = 1 & (val>>i);
            
            cur[i] = cur[i] - bit;
        }
    }
    
    void add(vector<int>&cur,int &val)
    {
        
        for(int i=0;i<cur.size();i++)
        {
            int bit = 1 & (val>>i);
            
            cur[i] = cur[i] + bit;
        }
    }
    
    bool check(vector<int>cur,vector<int>suffix)
    {
        for(int i=0;i<cur.size();i++)
        {
            if(cur[i]==0 && suffix[i]!=0)
                return false;
        }
        
        return true;
    }
    
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        
        int n = nums.size();
        
        
        vector<vector<int>>suffix_or(n,vector<int>(32,0));
        
        for(int i=n-1;i>=0;i--)
        {
            
            for(int j=31;j>=0;j--)
            {
                
                int bit  = (1 & (nums[i]>>j));
                
                if(bit==1)
                {
                      suffix_or[i][j]=1;
                }
                
            }
            
            if(i+1<n)
            {
                for(int j=31;j>=0;j--)
                {
                    suffix_or[i][j] += suffix_or[i+1][j];
                }
            }
        }
        
        
        vector<int>cur(32,0);
        
        int i=0;
        int j=-1;
        
        
        vector<int>res;
        while(i<n)
        {
            
            if(check(cur,suffix_or[i]))
            {
                res.push_back(max(1,j-i+1));
                
                remove(cur,nums[i]);
                i++;
            }
            
            else{
                j++;
                add(cur,nums[j]);
            }
            
        }
        
        
        return res;
    }
};
