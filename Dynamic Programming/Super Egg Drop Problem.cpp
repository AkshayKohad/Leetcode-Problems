#define ll long long
class Solution {
public:
    ll solve(int k,int n,vector<vector<ll>> &dp)
    {
        if(k==1)
            return n;
        if(n==0 || n==1)
            return n;
        
        if(dp[k][n]!=-1)
            return dp[k][n];
        ll mn=INT_MAX;
        int low=1,high=n;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int down=solve(k-1,mid-1,dp);
            int up=solve(k,n-mid,dp);
            ll temp=1+max(up,down);
            if(up>down)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mn=min(mn,temp);
        }
        
        return dp[k][n]=mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<ll>> dp(k+1,vector<ll>(n+1,-1));
        return solve(k,n,dp);
    }
};
