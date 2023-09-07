class Solution {
public:
    #define ll long long
    long long maxSum(vector<int>& nums, int m, int k) {
        
        ll result = 0;
        ll sum = 0;
        ll n = nums.size();
        
        unordered_map<ll,ll>mp;
        
        for(ll i=0;i<k;i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }
        
        if(mp.size()>=m)
        {
            result = max(result,sum);
        }
        
        for(ll i=k;i<n;i++)
        {
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            
            sum -= nums[i-k];
            
            mp[nums[i]]++;
            sum += nums[i];
            
            if(mp.size()>=m)
            {
                result = max(result,sum);
            }
        }
        
        return result;
    }
};
