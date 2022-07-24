class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        
        unordered_set<int>s;
        
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        unordered_map<int,set<int>>mp;
        for(auto a:s)
        {
            
            // counts Number of set bits
            int count = __builtin_popcount(a);
            
            mp[count].insert(a);
            
            
        }
        
        long long ans = 0;
        
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                if(i+j<k)
                    continue;
                 
                ans += mp[i].size()*mp[j].size();
                
            }
        }
        
        return ans;
    }
};
