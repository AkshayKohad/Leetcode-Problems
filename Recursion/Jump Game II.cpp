class Solution {
public:
    
    int solution(vector<int>&nums,int n)
    {
        if(n==1)
            return 0;
        
        int res = INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+i>=n-1)
                res=min(res,1+solution(nums,i+1));
        }
        
        return res;
        
            
    }
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        return solution(nums,n);
        
    }
};
