class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long result = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>=nums[i])continue;

            result += nums[i]-nums[i+1];
        }

        return result;
    }
};


