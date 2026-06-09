class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long result;

        long long maxi = nums[0];
        long long mini = nums[0];

        for(auto num : nums){
            maxi = max((long long)num,maxi);
            mini = min((long long)num,mini);
        }

        result = (maxi-mini)*k;
        return result;
    }
};
