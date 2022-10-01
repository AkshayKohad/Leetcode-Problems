class Solution {
public:
    
    bool check(int limit,int k,vector<int>&nums,int n)
    {
        
        int left = 0;
        
        int right = 0;
        
        int count = 0;
        while(right<n)
        {
            while(nums[right]-nums[left]>limit)
                left++;
            
            count += right-left;
            
            right++;
        }
        
        
        if(count>=k) return true;
        
        return false;
        
    }
    
    
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        int l = 0;
        
        int r = nums[n-1]-nums[0];
        
        int ans = -1;
        
        while(l<=r)
        {
            
            int mid = (l+r)/2;
            
            if(check(mid,k,nums,n))
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
