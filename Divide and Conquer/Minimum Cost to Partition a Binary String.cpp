class Solution {
public:
    #define ll long long
    long long solve(ll i,ll j,vector<int>&prefix,int encCost, int flatCost){
        if((j-i+1)%2 == 1){
            ll cnt_1 = prefix[j+1]-prefix[i];

            if(cnt_1>0)return cnt_1*(j-i+1)*(ll)encCost;
            else return (ll)flatCost;
        }

        ll cnt_1 = prefix[j+1]-prefix[i];
        ll res_val = 0;
        if(cnt_1>0){
            res_val = cnt_1*(j-i+1)*(ll)encCost;
        }else{
            res_val = (ll)flatCost;
        }

        ll result = res_val;
        ll mid = (j+i)/2;
        result = min(result,solve(i,mid,prefix,encCost,flatCost)+solve(mid+1,j,prefix,encCost,flatCost));

        return result;
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.length();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + (s[i] == '1' ? 1:0);
        }

        return solve(0,n-1,prefix,encCost,flatCost);
    }
};
