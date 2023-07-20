class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>remove_balance(n+1,0);
        
        remove_balance[0] = -nums[0];
        remove_balance[k] = nums[0];
        nums[0] = 0;
        int i;
        for( i=1;i<=n-k;i++)
        {
            remove_balance[i]+=remove_balance[i-1];
            
            nums[i] = nums[i] + remove_balance[i];
            
            if(nums[i]<0)
                return false;
            
            remove_balance[i] -= nums[i];
            
           
            remove_balance[i+k] += nums[i];
            
            nums[i] = 0;
            
        }
        
        for(;i<n;i++)
        {
            remove_balance[i] += remove_balance[i-1];
            
            nums[i] = nums[i] + remove_balance[i];
            
             if(nums[i]<0)
                return false;
            
         
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0) return false;
        }
        
        return true;
    }
};
