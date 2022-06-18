class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
         
         int l = 0;
        int h = nums.size()-1;
        
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(nums[mid]==target)
                return true;
            
            //leftside sorted condition
            
            if(nums[l]<nums[mid])
            {
                if(target>=nums[l] && target<=nums[mid])
                {
                    h = mid-1;
                }
                
                else
                {
                    l = mid+1;
                }
            }
            
            else if(nums[l]==nums[mid])
            {
                while(l<=mid && nums[l]==nums[mid])
                    l++;
            }
            
            //rightside sorted condition
    
            else if(nums[mid]<nums[h])
            {
                 if(target>=nums[mid] && target<=nums[h])
                 {
                     l = mid+1;
                 }
                
                else{
                    h = mid-1;
                }
            }
            
            else if(nums[mid]==nums[h])
            {
                while(h>=mid && nums[mid]==nums[h])
                    h--;
            }
        }
        
        return false;
        
    }
};
