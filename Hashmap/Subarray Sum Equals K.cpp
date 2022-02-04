class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix_sum[nums.size()];
        
        prefix_sum[0] = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            prefix_sum[i] = prefix_sum[i-1]+nums[i];
        }
        
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(prefix_sum[i]-k)!=mp.end())
            {
                ans += mp[prefix_sum[i]-k];
            }
            
            if(prefix_sum[i]==k)
                ans++;
            
            mp[prefix_sum[i]]++;
        }
        
        return ans;
    }
};
