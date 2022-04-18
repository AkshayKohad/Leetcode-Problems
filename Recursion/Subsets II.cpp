class Solution {
public:
    
    
    void solve(vector<int>nums,int i,vector<vector<int>>&res,vector<int>a)
    {
        if(i==nums.size())
        {
            res.push_back(a);
            return;
        }
        
        a.push_back(nums[i]);
        solve(nums,i+1,res,a);
        a.pop_back();
        
        int val = nums[i];
        int j = i;
        while(j<nums.size() && val==nums[j])
        {
            j++;
        }
        
        solve(nums,j,res,a);
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>a;
        
        sort(nums.begin(),nums.end());
        
    
        solve(nums,0,res,a);
        
        return res;
    }
};
