class Solution {
public:
    
    
    int solve(vector<int>&nums,int i,int &k,vector<int>&hashmap)
    {
        if(i==nums.size())
        {
            return 1;
        }
        
        int taken = 0;
        
        if( (nums[i]-k) < 0 || hashmap[nums[i]-k]==0)
        {
            hashmap[nums[i]]++;
            taken = solve(nums,i+1,k,hashmap);
            hashmap[nums[i]]--;
        }
        
        int not_taken = solve(nums,i+1,k,hashmap);
        
        return taken + not_taken;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        vector<int>hashmap(1001,0);
        
        return solve(nums,0,k,hashmap)-1;
        
    }
};
