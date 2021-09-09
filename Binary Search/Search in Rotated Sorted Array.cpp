class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
        
        
       if(n==1)
       {
            if(target==nums[0])
                return 0;
           return -1;
           
       }
        

        int i=0;
        int j=n-1;
        int k=-1;
        int s;
       
        
        for(int z=1;z<=n-1;z++)
        {
            if(nums[z]<nums[z-1])
            {
                k=z;
                s=k;
                break;
            }
        
        }
        
        if(k==-1)
        {
            while(i<=j)
            {
                int mid = (i+j)/2;
                if(nums[mid]>target)
                {
                    j = mid-1;
                }
                
                else if(nums[mid]<target)
                {
                    i = mid+1;
                }
                
                else
                    return mid;
            }
        }
        
        else
        { 
            while(k<=j)
            {
                int mid = (k+j)/2;
                 if(nums[mid]>target)
                {
                    j = mid-1;
                }
                
                else if(nums[mid]<target)
                {
                    k = mid+1;
                }
                
                else
                    return mid;
                
            }
            
             k = s-1;
            
            while(i<=k)
            {
                int mid = (i+k)/2;
                 if(nums[mid]>target)
                {
                    k = mid-1;
                }
                
                else if(nums[mid]<target)
                {
                    i = mid+1;
                }
                
                else
                    return mid;
            }
         }
        
        return -1;
    }
};
