class Solution {
public:
    int countPrimes(int n) {
        
        if(n==0 || n==1 || n==2)
        return 0;

        

        vector<int>sieve(n+1,1);

        for(int i=2;i<=n;i++)
        {
            if(sieve[i]==0) continue;

            for(int j=2*i;j<=n;j=j+i)
            {
                sieve[j] = 0;
            }

        }

        int result = 0;

        for(int i=2;i<n;i++)
        {
           
            result += sieve[i];
        }

        return result;
    }
};
