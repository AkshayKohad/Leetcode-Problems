class Solution {
public:
    int findMin(vector<int>& nums) {
     
        int n = nums.size();
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            int mid = (i+j)/2;
            
            if(i==mid)
            {
                if(nums[mid]>nums[mid+1])
                    return nums[(i+1)%n];
                else
                    i=mid+1;
            }
            
            if(nums[mid]<nums[j] && nums[j]>nums[i])
                i = mid+1;
            
            else if(nums[mid]<nums[i] && nums[i]>nums[j])
                j = mid-1;
            
            else if(nums[mid]>nums[i] && nums[mid]>nums[j])
            {
                if(nums[mid]>nums[mid+1])
                    return nums[(mid+1)%n];
                
                else
                    i=mid+1;
                    
            }
            
            
        }
        
        if(i==j)
            return nums[(i+1)%n];
         return -1;
    }
    
   
};
