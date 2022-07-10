class Solution {
public:
    
    int solve(int k,int n,vector<vector<int>>&memo)
    {
        if(k==0 || n==0)
            return 0;
        
        if(n==1)return 1;
        
        if(k==1) return n;
        
        
        if(memo[k][n]!=-1)
            return memo[k][n];
        
        int res = INT_MAX;
        
        int l = 1;
        int r = n;
        
       while(l<=r)
       {
           int mid = (l+r)/2;
           
           int  up = solve(k,n-mid,memo);
           int down = solve(k-1,mid-1,memo);
           
           
           int temp = 1+max(up,down);
           if(up>down)
               l = mid+1;
           
           else
               r = mid-1;
           
           res = min(res,temp);
       }
        
        return memo[k][n] = res;
    }
    int twoEggDrop(int n) {
        
        vector<vector<int>>memo(3,vector<int>(n+1,-1));
        return solve(2,n,memo);
    }
};
