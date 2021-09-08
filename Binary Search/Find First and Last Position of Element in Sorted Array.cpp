class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=-1;
        int y=-1;
        int n = nums.size();
        int i = 0;
        int j = n-1;
        
        while(i<=j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid]>target)
                j = mid-1;
            else if(nums[mid]<target)
                i = mid+1;
            
            else
            {
                while(mid-1>=0 && nums[mid]==nums[mid-1])
                {
                    mid--;
                }
                if(mid>=0)
                {
                    x=mid;
                }
                
                mid = (i+j)/2;
                while(mid+1<n && nums[mid]==nums[mid+1])
                {
                    mid++;
                }
                if(mid<n)
                {
                    y=mid;
                }
                
                break;
            }
         }
        
        vector<int>a;
        a.push_back(x);
        a.push_back(y);
        return a;
            
        
    }
};
