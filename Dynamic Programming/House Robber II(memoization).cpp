class Solution {
public:
    
    int solve(vector<int>nums,int size,int n,int flag, vector<vector<int>>&memo)
    {
        if(n==1)
        {
            if(flag==1)
            {
                if(nums[0]>nums[size-1])
                    return nums[0]-nums[size-1];
                
                else 
                    return 0;
            }
            
            else{
                return nums[0];
            }
        }
        
        if(n<=0)
        {
            return 0;
        }
        
        if(memo[n][flag]!=-1)
        {
            return memo[n][flag];
        }
        
        int res;
        int res2;
        if(n==size)
        {
             res =  nums[n-1]+max(solve(nums,size,n-2,flag=1,memo),solve(nums,size,n-3,flag=1,memo));
        
         res2 = max(res,solve(nums,size,n-1,flag=0,memo));
        }
        
        else{
        res =  nums[n-1]+max(solve(nums,size,n-2,flag,memo),solve(nums,size,n-3,flag,memo));
        
         res2 = max(res,solve(nums,size,n-1,flag,memo));
        }
        return memo[n][flag] = res2;
    }
    
    int rob(vector<int>& nums) {
        
    int n = nums.size();
        if(n==1)
            return nums[0];
        
        if(n==2)
            return max(nums[0],nums[1]);
        
        
        vector<vector<int>>memo(n+1,vector<int>(2,-1));
        return solve(nums,n,n,0,memo);
    }
};
