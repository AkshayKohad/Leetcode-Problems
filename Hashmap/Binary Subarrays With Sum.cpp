class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int result = 0;
        mp[0] = 1;
        int n = nums.size();
        int curSum = 0;
        for(int i=0;i<n;i++){
            curSum += nums[i];
            if(mp.find(curSum-goal)!=mp.end()){
                result += mp[curSum-goal];
            }
            mp[curSum]++;
        }

        return result;
    }
};
