class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int min_index = -1;
        int max_index = -1;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mini)
            {
                min_index = i;
                mini = nums[i];
            }
            
            if(nums[i]>maxi)
            {
                max_index = i;
                maxi = nums[i];
            }
        }
        
        
        int left = max(max_index,min_index)+1;
        
        int right = max(n-max_index,n-min_index);
        
        
        int res_min_index = min(max_index,min_index);
        
        int res_max_index = max(max_index,min_index);
        
        int res = (n-res_max_index) + (res_min_index+1);
        
        
        return min(res,min(left,right));
    }
};
