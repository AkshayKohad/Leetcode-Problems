class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&memo){
        if(i>j){
            return 0;
        }else if(i==j){
            return nums[i];
        }

        if(memo[i][j]!=-1)return memo[i][j];

        return memo[i][j] = max(nums[i] + min(solve(i+2,j,nums,memo),solve(i+1,j-1,nums,memo)), nums[j] + min(solve(i+1,j-1,nums,memo),solve(i,j-2,nums,memo)));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        vector<vector<int>>memo(n,vector<int>(n,-1));
        int res = solve(0,n-1,nums,memo);

        if(sum-res <= res)return true;
        return false;
    }
};
