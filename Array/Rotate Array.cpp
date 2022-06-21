class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
         k = k%n;
        
        if(k==0)
            return;
        
       int i = n-k;
        
       // int j=0;
        vector<int>res;
        for(int j=0;j<k;j++)
        {
            res.push_back(nums[i]);
            i++;
        }
        
        for(int j=0;j<n-k;j++)
        res.push_back(nums[j]);    
        
        
        nums=res;
        
    }
};
