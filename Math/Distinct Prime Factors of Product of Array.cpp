class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {

      int res = 1;

     for(auto k:nums)
     {
        res = max(res,k);
     }   

     vector<long long int>sieve(res+1,-1);

     for( int i=2;i<=res;i++)
     {
         if(sieve[i]!=-1)
          continue;

          for( int j = 2*i;j<=res;j=j+i)
          {
              if(sieve[j]==-1)
              {
                  sieve[j] = i;
              }
          }
     }



unordered_set<int>distinct_prime;
int cnt_primes = 0;

for(auto k:nums)
{
    int val = k;
   while(sieve[val]!=-1)
    {
        distinct_prime.insert(sieve[val]);
        val = val/sieve[val];
    }
  
    distinct_prime.insert(val);
   
}
    

  return distinct_prime.size();
    }
};
