class Solution {
public:
    
//    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&memo)
//     {
//         if(i>j)
//         return 0;
        
//         if(memo[i][j]!=-1)
//             return memo[i][j];
        
        
//         int res = INT_MIN;
        
//         for(int index = i;index<=j;index++)
//         {
//             int cost = nums[index]*nums[i-1]*nums[j+1] + 
//                 solve(i,index-1,nums,memo) + solve(index+1,j,nums,memo);
            
            
//             res = max(res,cost);
//         }
        
//         return memo[i][j] = res;
//     }
    

    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        
        
        nums.insert(nums.begin(),1);
        
        nums.push_back(1);
        
        // we hae kept n+2 for tabulation because if j==n and index = j
        // then in dp[index+1][j] it will give runtime error if it would 
        //have been n+1
        
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                
                if(i>j) continue;
                
                int maxi = INT_MIN;
                
                for(int index = i;index<=j;index++)
                {
                    int cost = nums[index]*nums[i-1]*nums[j+1] +
                        dp[i][index-1] + dp[index+1][j];
                    
                    maxi = max(maxi,cost);
                }
                
                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
    }
};
