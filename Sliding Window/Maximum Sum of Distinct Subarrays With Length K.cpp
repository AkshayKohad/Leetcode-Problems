class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        unordered_set<int>st;
        long long cur_sum = 0;
        long long result = 0;
        while(right<n){
            if(st.find(nums[right]) == st.end()){
                cur_sum += (long long)nums[right];
                st.insert(nums[right]);
                right++;
            }else{
                while(left<right && nums[left]!=nums[right]){
                    cur_sum -= (long long)nums[left];
                    st.erase(nums[left]);
                    left++;
                }
                cur_sum -= (long long)nums[left];
                left++;
                st.erase(nums[left]);
                st.insert(nums[right]);
                cur_sum += (long long)nums[right];
                right++;
            }


            if(right-left == k){
                result = max(result,cur_sum);
                cur_sum -= (long long)nums[left];
                st.erase(nums[left]);
                left++;
            }
        }

        return result;
    }
};
