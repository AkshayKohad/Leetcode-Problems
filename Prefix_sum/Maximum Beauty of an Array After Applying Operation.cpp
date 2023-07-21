class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
     
        int n = nums.size();
        
        int val = 0;
        for(int i=0;i<n;i++)
        {
            val = max(val,nums[i]);
            
        }
        
        vector<int>prefix(val+k+2,0);
        
        for(int i=0;i<n;i++)
        {
            int start = max(nums[i]-k,0);
            int end = nums[i]+k;
            
            prefix[start] += 1;
            prefix[end+1] -= 1;
            
        }
        
        int result = prefix[0];
        for(int i=1;i<prefix.size();i++)
        {
            prefix[i] += prefix[i-1];
            
            result = max(result,prefix[i]);
        }
        
        return result;
    }
};
