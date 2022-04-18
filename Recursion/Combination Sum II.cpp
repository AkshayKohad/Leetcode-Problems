class Solution {
public:
    
    void solve(vector<int>& candidates,int target,vector<int>a,vector<vector<int>>&res,int n)
    {
        if(target == 0)
        {
            res.push_back(a);
            return;
        }
        
        if(n==0)
        {
            return;
        }
        
        if(target<0)
            return;
        
        a.push_back(candidates[n-1]);
        solve(candidates,target-candidates[n-1],a,res,n-1);
        a.pop_back();
        
        int j = n;
        int val = candidates[n-1];
        
        while(j>0 && candidates[j-1]==val)
        {
            j--;
        }
        solve(candidates,target,a,res,j);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>a;
        int n = candidates.size();
        solve(candidates,target,a,res,n);
        
        return res;
    }
};
