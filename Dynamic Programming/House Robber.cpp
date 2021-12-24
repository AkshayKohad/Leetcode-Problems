class Solution {
public:
    
    int solution(vector<int>&nums,int n)
    {
        if(n<=0)
            return 0;
        
        int ans =  nums[n-1]+max(solution(nums,n-2),solution(nums,n-3));
        
        int ans1 = solution(nums,n-1);
        
        return max(ans,ans1);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int val=0;
            int val1=0;
            
            if(i-2>=0)
            {
                val = dp[i-2];
            }
            
            if(i-3>=0)
            {
                val1 = dp[i-3];
            }
            
            int ans = nums[i-1]+max(val,val1);
            int ans1 = dp[i-1];
            
            dp[i] = max(ans,ans1);
        }
        
        return dp[n];
        //return solution(nums,n);
    }
};
