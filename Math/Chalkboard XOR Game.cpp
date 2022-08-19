class Solution {
public:
    bool xorGame(vector<int>& nums) {
        
        int res = 0;
        
        for(auto k:nums)
        {
            res ^= k;
        }
        
        return res == 0 ||  nums.size()%2 == 0;
    }
};
