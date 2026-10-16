class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minimum_product = 1;
        int maximum_product = 1;
        int n = nums.size();
        int result = nums[0];
        for(int i=0;i<n;i++){
            int val = max({minimum_product*nums[i],maximum_product*nums[i],nums[i]});
            minimum_product = min({minimum_product*nums[i],maximum_product*nums[i],nums[i]});
            maximum_product = val;
            result = max(result,maximum_product);
        }
        return result;
    }
};
