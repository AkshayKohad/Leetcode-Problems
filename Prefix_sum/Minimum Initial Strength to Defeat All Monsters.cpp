class Solution {
public:
#define ll long long
    bool check(ll limit,vector<ll>&power,vector<int>&monsters){
        for(int i=0;i<monsters.size();i++){
            ll cur_power = limit + power[i];
            if(cur_power < monsters[i])return false;

            limit -= monsters[i];
            limit = max(limit,0ll);
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<ll>power(n+1,0ll);

        for(auto boost : boosts){
            int l = boost[0];
            int r = boost[1];
            ll v = boost[2];
            power[l]+=v;
            power[r+1]-=v;
        }

        for(int i=1;i<=n;i++){
            power[i] += power[i-1];
        }

        ll result = 0;
        ll pref_sum = 0;
        for(int i=0;i<n;i++){
            if(power[i]<monsters[i]){
                result = pref_sum + monsters[i] - power[i];
            }
            pref_sum = pref_sum + monsters[i];
        }
        return result;
    }
};
