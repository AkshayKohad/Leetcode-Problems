class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]==0)
            {
                nums[i] = -1;
            }
            
            
        }
        
       unordered_map<int,int>mp;
        int curr_sum = 0;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            curr_sum += nums[i];
            
            if(curr_sum==0)
                res = max(res,i+1);
            
            
            if(mp.find(curr_sum)!=mp.end())
            {
                res = max(res,i-mp[curr_sum]);
            }
            
            else{
                mp[curr_sum] = i;
            }
        }
        
        
        return res;
    }
};
