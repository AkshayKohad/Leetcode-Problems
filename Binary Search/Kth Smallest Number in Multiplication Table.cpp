#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    
     ll l=1;
        ll r = m*n;
        ll ans =-1;

        while(l<=r)
        {
            ll mid = (l+r)/2;

            ll cnt = 0;

            for(ll i=1;i<=m;i++)
            {
                cnt += min((ll)n,mid/i);

            }

            if(cnt>=k)
            {
                ans = mid;
                r = mid-1;

            }

            else{
                l = mid+1;
            }
        }

    cout<<ans<<endl;
}
