class Solution {
public:
    
    
    void solve(int n,int i,int k,vector<int>a,vector<vector<int>>&res)
    {
        if(k==0)
        {
            res.push_back(a);
            return;
        }
        
        for(int j=i;j<=n;j++)
        {
            a.push_back(j);
            solve(n,j+1,k-1,a,res);
            a.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>res;
        vector<int>a;
        
        
        solve(n,1,k,a,res);
        
        return res;
    }
};
