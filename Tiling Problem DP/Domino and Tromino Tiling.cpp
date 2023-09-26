class Solution {
public:

#define ll long long
#define mod 1000000007


ll solve(ll n,vector<ll>&memo)
{
    if(n==0)return 1;
    
    if(n==1)return 0;
    
    if(memo[n]!=-1)
        return memo[n];
    
    // in even case
    if(n%2==0)
    {
        ll res=0;
        //vertical domino
        if(n-2>=0)
        {
            res = (solve(n-2,memo))%mod;
        }
        ll res1=0;
        // tromino with two possiblities
        if(n-3>=0)
        {
            res1 = (2*solve(n-3,memo))%mod;
        }
        
        ll res2=0;
        
        // two horizontal domino
        if(n-4>=0)
        {
            res2 = (solve(n-4,memo))%mod;
        }
        
        return memo[n] = (res+res1+res2)%mod;
    }
    
    // in odd case
    else{
        
         ll res1=0;
        //one tromino
        if(n-3>=0)
        {
            res1 = (solve(n-3,memo))%mod;
        }
        
        ll res2=0;
        //one domino
        if(n-2>=0)
        {
            res2 = (solve(n-2,memo))%mod;
        }
        
        return memo[n] = (res1+res2)%mod;
    }
   return 0;
}

    int numTilings(int n) {
        vector<ll>memo(2*n+1,-1);
    return solve(2*n,memo);
    }
};
