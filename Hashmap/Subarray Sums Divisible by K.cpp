class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int curSum = 0;
        int n = nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            curSum += nums[i];
            int rem = (curSum%k + k )%k;
            if(mp.find(rem)!=mp.end()){
                result += mp[rem];
            }
            mp[rem]++;
        }

        return result;
    }
};
