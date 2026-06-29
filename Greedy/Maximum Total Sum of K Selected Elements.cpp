class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<>());
        long long result = 0;
        int n = nums.size();
        int i=0;
        while(k>0 && mul>0 && i<n){
            result += (long long)nums[i]*mul;
            mul--;
            i++;
            k--;
        }

        while(k>0 && i<n){
            result += nums[i];
            i++;
            k--;
        }

        return result;
    }
};
