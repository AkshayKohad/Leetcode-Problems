class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = 0;
        long long prod = 1;
        for(auto num : nums){
            sum = sum+num;
        }
        int n = nums.size();
        int mini_index = n;
        for(int i=n-1;i>=0;i--){
            sum -= nums[i];

            if(prod == sum)mini_index = i;
            if(prod>sum)break;
            
            if(prod > LLONG_MAX/nums[i])break;
            prod = prod*nums[i];
        }

        return mini_index == n ? -1 : mini_index;
    }
};
