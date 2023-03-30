class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==3)
            return 0;
        
        sort(nums.begin(),nums.end());
        
       
        
        int possiblity = INT_MAX;
        
           possiblity =  min(possiblity, nums[n-1]-nums[2]);
        
           possiblity =  min(possiblity, nums[n-3]-nums[0]);
        
          possiblity = min(possiblity,nums[n-2]-nums[1]);
        
        return possiblity;
    }
};
