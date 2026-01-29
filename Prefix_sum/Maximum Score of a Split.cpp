class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long prefix_sum = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            prefix_sum += nums[i];
        }

        long long suffix_min = nums[n-1];

        long long result = prefix_sum - suffix_min;

        for(int i=n-2;i>=1;i--){
            prefix_sum -= nums[i];
            suffix_min = min(suffix_min,(long long)nums[i]);
            result = max(result,prefix_sum-suffix_min);
        }
        return result;
    }
};
