class Solution {
public:
    #define ll long long
    long long maxScore(vector<int>& nums) {
        ll n = nums.size();
        if(n==0)return 0;
        if(n==1)return (ll)nums[0]*(ll)nums[0];
        ll res = 0;
       
        for(ll i=0;i<n;i++){
            ll gcd = 0;
            ll lcm = 0;
            bool first = true;
            for(ll j=0;j<n;j++){
                if(i==j)continue;
                if(first){
                    gcd = nums[j];
                    lcm = nums[j];
                    first = false;
                    continue;
                }

                gcd = __gcd((ll)nums[j],gcd);
                lcm = (lcm*(ll)nums[j])/__gcd((ll)nums[j],lcm);
            }

            res = max(res,lcm*gcd);
            
        }
         ll lcm = nums[0];
         ll gcd = nums[0];
         for(ll i=1;i<n;i++){
            gcd = __gcd((ll)nums[i],gcd);
            lcm = (lcm*(ll)nums[i])/__gcd((ll)nums[i],lcm);
        }
        res = max(res,lcm*gcd);
        return res;
    }
};
