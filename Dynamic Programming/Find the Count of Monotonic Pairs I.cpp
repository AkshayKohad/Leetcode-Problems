class Solution {
public:
   
    #define mod 1000000007
    
    int solve(int i,int &n,vector<int>&nums,int prev,vector<vector<int>>&memo)
    {
         if(i==n)
         {
            return 1;
         }

         if(memo[i][prev]!=-1)
         return memo[i][prev];

         if(i==0)
         {
            int res = 0;
            for(int j=0;j<=nums[i];j++)
            {
                res = (res + solve(i+1,n,nums,j,memo))%mod;
            }

            return memo[i][prev] = res;
         }
         
         else
         {
            int res = 0;

            for(int j=0;j<=nums[i];j++)
            {
                if(j<prev || nums[i-1]-prev<nums[i]-j)
                continue;

                res = (res + solve(i+1,n,nums,j,memo))%mod;
            }

            return memo[i][prev] = res;
         }

         return 0;
    }
    int countOfPairs(vector<int>& nums) {
        
        int n = nums.size();
       vector<vector<int>>memo(n+1,vector<int>(51,-1));
        return solve(0,n,nums,0,memo);
    }
};
