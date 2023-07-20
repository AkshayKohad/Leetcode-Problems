class Solution {
public:
    
    int solve(int i,vector<int>&nums,int &target,int &n,vector<int>&memo)
    {
        if(i==n-1)
            return 0;
        
        if(memo[i]!=-2)
            return memo[i];
        
        
        int res = -1;
        
        for(int j=i+1;j<n;j++)
        {
            if(abs(nums[i]-nums[j]) <= target)
            {
                int ans = solve(j,nums,target,n,memo);
                
                if(ans==-1)
                    continue;
                
                ans = ans + 1;
                
                res = max(res,ans);
            }
        }
        
        return memo[i] = res;
        
        
    }
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<int>memo(n,-2);
        return solve(0,nums,target,n,memo);
    }
};
