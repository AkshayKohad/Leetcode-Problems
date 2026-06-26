class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result_subarray_cnt = 0;
        for(int i=0;i<n;i++){
            int cnt_target = 0;
            for(int j=i;j<n;j++){
                if(nums[j] == target)cnt_target++;
                int res_len = j-i+1;
                if(res_len/2 < cnt_target)result_subarray_cnt++;
            }
        }
        return result_subarray_cnt;
    }
};
