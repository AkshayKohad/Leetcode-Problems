class Solution {
public:
    #define ll long long
    #define mod 1000000007

    ll solve(ll t,ll ch,vector<vector<ll>>&memo){
        if(t==0)return 1;

        if(memo[t][ch]!=-1)return memo[t][ch];
        
        if(ch==25){
            return memo[t][ch] = (solve(t-1,0,memo) + solve(t-1,1,memo))%mod;
        }else{
            return memo[t][ch] = solve(t-1,ch+1,memo);
        }
    }
    int lengthAfterTransformations(string s, int t) {
        vector<vector<ll>>memo(t+1,vector<ll>(26,-1));
        ll ch = 0;
        for(ll i=0;i<26;i++)
        solve(t,i,memo);

        ll result = 0;
        
        for(ll i=0;i<s.length();i++)
        result = (result + memo[t][s[i]-'a'])%mod;

        return result;
    }
};
