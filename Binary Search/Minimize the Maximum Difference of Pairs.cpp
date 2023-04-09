class Solution {
public:
    
    
    bool check(int diff,int p,vector<int>&nums)
    {
       int count_pairs = 0;
        
        int in = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(in)
            {
                in = 0;
                continue;
            }
            
            if(nums[i]-nums[i-1]<=diff)
            {
                in = 1;
                count_pairs++;
            }
        }
        
        if(count_pairs>=p)
            return true;
        
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(check(mid,p,nums))
            {
                ans = mid;
                r = mid-1;
                
            }
            
            else{
                l = mid+1;
            }
        }
        
        return ans;
            
    }
};
