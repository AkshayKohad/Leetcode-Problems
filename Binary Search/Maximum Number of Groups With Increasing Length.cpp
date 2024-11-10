class Solution {
public:
    #define ll long long

    bool check(ll grp_cnt,vector<int>&usageLimits){
        ll group = 0;
        ll pref_sum = 0;
        ll n = usageLimits.size();

        for(int i=0;i<n;i++){
            pref_sum += usageLimits[i];

            if(pref_sum >= group+1){
                pref_sum -= (group+1);
                group++;
            }
        }

        if(group>=grp_cnt)return true;
        return false;
    }
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(),usageLimits.end());
        ll n = usageLimits.size();
        ll sum = 0;
        for(ll i=0;i<n;i++){
            sum += usageLimits[i];
        }

        ll l=1;
        ll r=sum;
        ll ans = -1;
        while(l<=r){
            ll mid = (l+r)/2;

            if(check(mid,usageLimits)){
                ans =  mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};
