class Solution {
public:
    
    int solution(vector<int>&nums,int n)
    {
        if(n==1)
            return 0;
        
        int res = INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+i>=n-1)
                res=min(res,1+solution(nums,i+1));
        }
        
        return res;
        
            
    }
    int jump(vector<int>& nums) {
        
        int n = nums.size();
       // return solution(nums,n);
        
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=n;i++)
        {
            dp[i] = INT_MAX;
            for(int j=1;j<i;j++)
            {
                if(nums[j-1]+j>=i)
                    dp[i] = min(dp[i],1+dp[j]);
            }
            
        }
        
        return dp[n];
        
    }
};
