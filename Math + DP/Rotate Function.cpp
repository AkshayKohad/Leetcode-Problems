class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int prefix_sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            prefix_sum += nums[i];
        }

        int cur_sum = 0;
        for(int i=0;i<n;i++){
            cur_sum += i*nums[i];
        }
        int result = cur_sum;
        int cur_start_index = 0;
        for(int i=0;i<n-1;i++){
            cur_sum = cur_sum - prefix_sum;
            cur_sum += n*nums[cur_start_index];
            cur_start_index++;
            result = max(result,cur_sum);
        }

        return result;
    }
};
