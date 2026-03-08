class Solution {
public:
    #define ll long long
    #define mod 1000000007

    ll power(ll a, ll n){
        if(n==0)return 1;
        if(n==1)return a;

        if(n%2==0){
            ll ans = power(a,n/2);
            return (ans*ans)%mod;
        }

        ll ans = power(a,(n-1)/2);
        ans = (ans*ans)%mod;
        return (ans*a)%mod;
    }
    int sumOfNumbers(int l, int r, int k) {
        ll total_number = r-l+1;
        ll sum_of_all_digits = 0;
        for(ll i=l;i<=r;i++){
            sum_of_all_digits += i;
        }

        ll geometric_for_place_value = (power((ll)10,k) - 1 + mod);
        geometric_for_place_value = (geometric_for_place_value*power(9, mod-2))%mod; // division in modulo is inverse(num) -> num^(mod-2);
        // formula -> (sum_of_all_digits)*(total_number^(k-1))*((10^(k-1)-1)/9)

        ll result = (sum_of_all_digits*power(total_number,k-1))%mod;
        result = (result*geometric_for_place_value)%mod;
        return result;
    }
};
