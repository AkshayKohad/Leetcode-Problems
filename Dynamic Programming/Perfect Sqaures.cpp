class Solution {
public:
    
    int solve(vector<int>&a,int m,int n,vector<vector<int>>&memo)
    {
        if(n==0)
            return 0;
        
        if(m==0 || n<0)
            return -1;
        
        
        if(memo[m][n]!=-2)
            return memo[m][n];
        
        int res1 = solve(a,m-1,n,memo);
        int res2 = solve(a,m,n-a[m-1],memo);
        
        if(res1==-1 && res2==-1)
            return memo[m][n] = -1;
        
        if(res1==-1)
            return memo[m][n] = res2+1;
        
        if(res2==-1)
            return memo[m][n] = res1;
        
        return memo[m][n] = min(res1,res2+1);
    }
    int numSquares(int n) {
        
        vector<int>a;
        
        int j = 1;
        while(j*j<n)
        {
            a.push_back(j*j);
            j++;
        }
        
        if(j*j==n)
            return 1;
        
        int m = a.size();
        vector<vector<int>>memo(m+1,vector<int>(n+1,-2));
       return solve(a,m,n,memo);
    }
};
