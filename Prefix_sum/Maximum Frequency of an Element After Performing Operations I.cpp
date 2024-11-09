class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(),nums.end());
        int maximum_value = nums[n-1];
        vector<int>freq(maximum_value+1,0);

        for(auto num:nums){
            freq[num]++;
        }

        vector<int>prefix_sum(maximum_value+1,0);
        for(int i=1;i<=maximum_value;i++){
            prefix_sum[i] += prefix_sum[i-1]+freq[i];
        }

        for(int i=1;i<=maximum_value;i++){
            int left = max(1,i-k);
            int right = min(maximum_value,i+k);
            
            int total_operations = prefix_sum[right]-prefix_sum[left-1] - freq[i];

            int required_operations = min(total_operations,numOperations);

            int res_freq = freq[i] + required_operations;

            result = max(result,res_freq);
        }

        return result;
    }
};

