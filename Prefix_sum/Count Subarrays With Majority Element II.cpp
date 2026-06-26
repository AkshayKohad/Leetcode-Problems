class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>prefix(n,0);

        prefix[0] = nums[0] == target ? 1:-1;

        long long result = 0;
        unordered_map<int,int>mp;
        long long cur_sum = 0;
        mp[0] = 1;
        long long left_valid_cnts = 0;
        for(int i=0;i<n;i++){
            if(target == nums[i]){
                left_valid_cnts += mp[cur_sum];
                cur_sum++;
            }else{
                cur_sum--;
                left_valid_cnts -= mp[cur_sum];
            }

            mp[cur_sum]++;
            result += left_valid_cnts;
        }
        return result;
    }
};
