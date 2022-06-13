class Solution {
public:
    
    
    int solve(vector<int>& candidates,int target,int n,vector<int>&memo)
    {
        if(target<0)
            return 0;
        
         if(target==0)
         {
             
             return 1;
         }
        
        
        
//         if(i>=n)
//             return 0;
        

        
        if(memo[target]!=-1)
            return memo[target];
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            res += solve(candidates,target-candidates[i],n,memo);
        }
        
       
        
        
        return memo[target] = res;
        
       
    }

    
    int combinationSum4(vector<int>& candidates, int target) {
        
        
        int n = candidates.size();
        vector<int>memo(target+1,-1);
        return solve(candidates,target,n,memo);
    }
};

    
