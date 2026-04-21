class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix_max(n);
        vector<int>suffix_min(n);
        int cur_max = 0;
        for(int i=0;i<n;i++){
            prefix_max[i] = max(cur_max,nums[i]);
            cur_max = prefix_max[i];
        }

        int cur_min = cur_max;
        for(int i=n-1;i>=0;i--){
            suffix_min[i] = min(cur_min,nums[i]);
            cur_min = suffix_min[i];
        }

        for(int i=0;i<n;i++){
            int val = prefix_max[i] - suffix_min[i];
            if(val <= k)return i;
        }

        return -1;
    }
};
