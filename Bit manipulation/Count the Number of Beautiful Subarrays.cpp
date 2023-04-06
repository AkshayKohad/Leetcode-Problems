class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        long long result = 0;
        int prefix_xor = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
          prefix_xor = prefix_xor ^ nums[i];

          if(prefix_xor==0)
          result++;

          if(mp.find(prefix_xor) != mp.end())
          {
              result = result + mp[prefix_xor];
          }

          mp[prefix_xor]++;

        }

        return result;
    }
};
