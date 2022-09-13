class Solution {
public:
    
    
    bool check(vector<int>&bits,int val)
    {

        
        for(int i=0;i<=31;i++)
        {
            
            int bit = 1 & (val>>i);
            
            if(bit==1)
            {
                if(bits[i]==1) return false;
            }
        }
        
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        
        vector<int>bits(32,0);
        
        
        int n = nums.size();
        
        int i=0;
        int j=0;
        
        int res = 1;
        while(j<n)
        {
          
            if(check(bits,nums[j]))
            {
                
                for(int k=0;k<=31;k++)
                {
                    int bit = 1 & (nums[j]>>k);
                    

                    if(bit==1)
                    bits[k] = bit;
                }

                res = max(res,j-i+1);
                
                
                j++;
            }
            
            else{
                for(int k=0;k<=31;k++)
                {
                    int bit = 1 & (nums[i]>>k);
                    
                    if(bit==1)
                    bits[k] = 0;
                }
                
                i++;
                
                res = max(res,j-i+1);
            }
            
            
            
        }

        return res;
    }
};
