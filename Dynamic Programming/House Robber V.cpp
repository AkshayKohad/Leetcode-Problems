class Solution {
public:
    long long solve(vector<int>&nums,vector<int>&colors,int n,vector<long long>&memo){
        if(n<=0)return 0;

        if(memo[n]!=-1)return memo[n];
        long long result = 0;
        
        if(n-1>=0){
            result = max(result,(long long)nums[n-1]+solve(nums,colors,n-3,memo));
            result = max(result,(long long)nums[n-1]+solve(nums,colors,n-2,memo));

            if(n-2>=0){
                if(colors[n-2] != colors[n-1]){
                    result = max(result,(long long)nums[n-1]+solve(nums,colors,n-1,memo));
                }
            }
        }
        result = max(result,solve(nums,colors,n-1,memo));
        return memo[n] = result;
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long>memo(n+1,-1);
        return solve(nums,colors,n,memo);
    }
};
