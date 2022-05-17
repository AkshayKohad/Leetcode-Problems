class Solution {
public:
    
    int solve(int n,vector<int>&nums,int val, map<pair<int,int>,int>&m)
    {
        if(n==0)
            return val;
        
        if(m.find({n,val})!=m.end())
            return m[{n,val}];
        
        int res = max(max(val,solve(n-1,nums,val*nums[n-1],m)),solve(n-1,nums,nums[n-1],m));
        
        m[{n,val}] = res;
        
        return m[{n,val}];
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
       
        map<pair<int,int>,int>m;
        return solve(n-1,nums,nums[n-1],m);
    }
};
