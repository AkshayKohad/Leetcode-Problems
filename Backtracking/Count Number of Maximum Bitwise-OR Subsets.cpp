class Solution {
public:
    void solve(int i,int cur_val,int &res,int &n,vector<int>&nums,int& result){
        if(i==n){
            if(cur_val == res){
                result++;
            }
            return;
        }

        solve(i+1,cur_val,res,n,nums,result);
        solve(i+1,cur_val|nums[i],res,n,nums,result);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0;
        for(auto num : nums){
            res = res | num;
        }
        int result = 0;
        int n = nums.size();
        solve(0,0,res,n,nums,result);
        return result;
    }
};
