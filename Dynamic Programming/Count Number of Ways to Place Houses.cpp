class Solution {
public:
#define ll long long
#define mod 1000000007


   ll solve(int n,int house,vector<vector<ll>>&memo)
   {
       if(n==0)
       return 1;
       
       if(memo[n][house]!=-1)
       return memo[n][house];

       if(house==0)
      return memo[n][house] = (solve(n-1,1,memo) + solve(n-1,0,memo))%mod;

      else{
          return memo[n][house] = solve(n-1,0,memo)%mod;
      }
   }
    int countHousePlacements(int n) {

       vector<vector<ll>>memo(n+1,vector<ll>(2,-1));
       ll val =  solve(n,0,memo);

     return (val*val)%mod;   
    }
};
