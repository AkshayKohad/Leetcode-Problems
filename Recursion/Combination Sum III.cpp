class Solution {
public:
    
   void solve(vector<int>nums,int n,vector<int>a,vector<vector<int>>&res,int k,int target)
    {
        if(target == 0 && k == 0)
        {
            res.push_back(a);
            return;
        }
        
        if(n==0)
            return;
        
        if(k<=0)
            return;
        if(target<=0)
            return;
        
        a.push_back(nums[n-1]);
        solve(nums,n-1,a,res,k-1,target-nums[n-1]);
        a.pop_back();
        
        solve(nums,n-1,a,res,k,target);
            
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int>nums;
        
        for(int i=1;i<=9;i++)
        {
            nums.push_back(i);
        }
        
        int n = nums.size();
        
        vector<int>a;
        vector<vector<int>>res;
        
        solve(nums,n,a,res,k,target);
        
        return res;
    }
};
