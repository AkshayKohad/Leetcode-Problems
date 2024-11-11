class Solution {
public:
    #define mod 1000000007

    int solve(int i,int &n,vector<int>&nums,int gcd1,int gcd2,vector<vector<vector<int>>>&memo){
        if(i==n){
            return gcd1==gcd2;
        }

        if(memo[i][gcd1][gcd2]!=-1)return memo[i][gcd1][gcd2];
        
        return memo[i][gcd1][gcd2] = (solve(i+1,n,nums,__gcd(gcd1,nums[i]),gcd2,memo) + (solve(i+1,n,nums,gcd1,__gcd(nums[i],gcd2),memo) + solve(i+1,n,nums,gcd1,gcd2,memo))%mod)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(0,n,nums,0,0,memo)-1;
    }
};
