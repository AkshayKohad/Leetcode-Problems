class Solution {
public:
    
    int solve(vector<int>&res,int i,int m,vector<int>&nums,vector<vector<int>>&memo)
    {
        
        
        if(i==res.size() && m==0)
            return 0;
        
        if(i==res.size() || m==0)
            return -1;
        
        if(memo[i][m]!=-2)
            return memo[i][m];
        
        
        int ans = INT_MAX;
        for(int j=i;j<res.size();j++)
        {
            int val = res[j]-res[i]+nums[i];
            
            int val2 = solve(res,j+1,m-1,nums,memo);
            
            if(val2==-1)
                continue;
            
            int final_val = max(val,val2);
            
            ans = min(final_val,ans);
        }
        
        if(ans==INT_MAX)
            return memo[i][m] = -1;
        
        return memo[i][m] = ans;
        
    }
        
    
    int splitArray(vector<int>& nums, int m) {
        
        vector<int>res;
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            res.push_back(sum);
        }
        
        vector<vector<int>>memo(n,vector<int>(m+1,-2));
        
        return solve(res,0,m,nums,memo);
    }
};
