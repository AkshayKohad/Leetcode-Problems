// Approach 1(Tabulation)


class Solution {
public:
    
    bool solve(vector<int>nums,int n,int sum,vector<vector<int>>&memo)
    {
        if(sum==0)
            return true;
        
        if(sum<0)
            return false;
        
        if(n==0)
            return false;
        
        
        if(memo[n][sum]!=-1)
            return memo[n][sum];
        
        return solve(nums,n-1,sum-nums[n-1],memo)  || solve(nums,n-1,sum,memo);
    }
  
  
  
  
  
  
    bool canPartition(vector<int>& nums) {
     
        int n = nums.size();
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        
        if(sum%2==1)
            return false;
        
     //   vector<vector<int>>memo(n+1,vector<int>((sum/2)+1,-1));
        
     //  return solve(nums,n,sum/2,memo);
        
        sum/=2;
        
        int dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=sum;i++)
        {
            dp[0][i] = 0;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool take;
                bool not_take;
                
                if(j>=nums[i-1])
                    take = dp[i-1][j-nums[i-1]];
                
                else{
                    take = false;
                }
                
                
                not_take = dp[i-1][j];
                
                dp[i][j] = take || not_take;
            }
        }
        
        return dp[n][sum];
         
    }
};






// Approach 2 (Tabulation space optimization)

class Solution {
public:
    
       bool canPartition(vector<int>& nums) {
     
        int n = nums.size();
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        
        if(sum%2==1)
            return false;
        
     //   vector<vector<int>>memo(n+1,vector<int>((sum/2)+1,-1));
        
     //  return solve(nums,n,sum/2,memo);
        
        sum/=2;
        
       
        
        vector<int>curr(sum+1,0);
        vector<int>prev(sum+1,0);
        
        prev[0]=1;
        curr[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool take;
                bool not_take;
                
                if(j>=nums[i-1])
                    take = prev[j-nums[i-1]];
                
                else{
                    take = false;
                }
                
                
                not_take = prev[j];
                
                curr[j] = take || not_take;
            }
            
            prev = curr;
        }
        
        return curr[sum];
         
    }
};
