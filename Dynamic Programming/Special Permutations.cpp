class Solution {
public:
    #define ll long long
    #define mod 1000000007
    
    int solve(vector<int>&nums,int &n,ll bit_val,vector<vector<ll>>&memo,int val_count,int prev_index)
    {
        
        
        if(val_count == n)
        {
            
            return 1;
        }
        
        if(memo[prev_index+1][bit_val]!=-1)
            return memo[prev_index+1][bit_val];
        
        ll res = 0;
        for(int j=0;j<n;j++)
        {
            int bit = (bit_val>>j)&1;
            
            if(bit == 0)
            {
                if(prev_index == -1 || nums[prev_index]%nums[j]==0 || nums[j]%nums[prev_index] == 0)
                {
                
        
                 res = (res + solve(nums,n,bit_val | (1<<j),memo,val_count+1,j))%mod;
                    
                
               
                }
            }
        }
        
        return memo[prev_index+1][bit_val] = res;
    }
    
    int specialPerm(vector<int>& nums) {
     
        int n = nums.size();
        
      
        
        ll bit_val = 0;
        vector<vector<ll>>memo(n+1,vector<ll>(pow(2,15)-1,-1));
        vector<int>a;
        
        ll count = 0;
        
       return solve(nums,n,0,memo,0,-1);
        
        
    }
};
