class Solution {
public:

    #define mod 1000000007

    int nthMagicalNumber(int n, int a, int b) {
        
        long long int l = min(a,b);

        long long int r = l*n;

        long long int lcm = (a*b)/__gcd(a,b);
        while(l<r)
        {
            long long int mid = (l+r)/2;

            long long int count = mid/a + mid/b - mid/lcm;

            if(count<n)
            l = mid+1;

            else
            r = mid;

        }

        return l%mod;
    }
};
