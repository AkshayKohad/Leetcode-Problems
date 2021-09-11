class Solution {
public:
    
    int solution(int i,int j,vector<int>&nums)
    {
         int mid = (i+j)/2;
         if(mid==0 )
        {
            
            if(nums[mid]>nums[mid+1])
            return mid;
            
            
            
        }    
        
        else if(mid == nums.size()-1 )
        {
            if(nums[mid]>nums[mid-1])
            return mid;
        }
        
        else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            return mid;
            
        if(i==j)
        {   
            return -1;
        }
        
        
        
        int res = solution(i,mid,nums);
        int res1 = solution(mid+1,j,nums);
        
        if(res==-1 && res1==-1)
            return -1;
        
        else if(res==-1)
            return res1;
        else if(res1==-1)
            return res;
        
        else
            return res;
        
    }
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int i=0;
        int j=n-1;
        int mid = (i+j)/2;
        if(n==1)
            return 0;
       
        return solution(i,j,nums);
        
    }
};
