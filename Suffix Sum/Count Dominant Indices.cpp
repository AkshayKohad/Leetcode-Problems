class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 1;
        int n = nums.size();
        int sum = nums[n-1];
        int result = 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]*cnt > sum)result++;

            sum += nums[i];
            cnt++;
        }
        return result;
    }
};
