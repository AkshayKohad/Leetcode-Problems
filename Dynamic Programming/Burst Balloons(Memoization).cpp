class Solution {
public:
    
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&memo)
    {
        if(i>j)
        return 0;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        
        int res = INT_MIN;
        
        for(int index = i;index<=j;index++)
        {
            int cost = nums[index]*nums[i-1]*nums[j+1] + 
                solve(i,index-1,nums,memo) + solve(index+1,j,nums,memo);
            
            
            res = max(res,cost);
        }
        
        return memo[i][j] = res;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        
        
        nums.insert(nums.begin(),1);
        
        nums.push_back(1);
        
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        
        return solve(1,n,nums,memo);
        
    }
};
