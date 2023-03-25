class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
    
       int n = nums.size();
        
       vector<int>mod_result(value,0);
        
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
              int divisor = ceil(abs(nums[i])/value);
              
                if(abs(nums[i])%value == 0 )
                nums[i] += value*divisor;
                
                else
                    nums[i] += value*(divisor+1);
            }
            
            mod_result[nums[i]%value]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i<value)
            {
               if(mod_result[i]==0)
                 return i; 
                
                else
                    mod_result[i]--;
            }
            
            else{
                if(mod_result[i%value]==0)
                    return i;
                
                else
                    mod_result[i%value]--;
            }
        }
            
        return n;    
    }
};
