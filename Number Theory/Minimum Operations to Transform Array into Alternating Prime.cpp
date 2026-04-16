class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int>isPrime(100001,0);
        vector<int>allPrimes;
        vector<int>non_primes;
        int last_prime = 100003;
        
        for(int i=2;i*i<=100000;i++){
            if(isPrime[i]==1)continue;

            isPrime[i] = 0;
            allPrimes.push_back(i);
            for(int j=i*i;j<=100000;j+=i){
                non_primes.push_back(j);
                isPrime[j] = 1;
            }
        }
        non_primes.push_back(0);
        non_primes.push_back(1);
        sort(allPrimes.begin(),allPrimes.end());
        sort(non_primes.begin(),non_primes.end());
        
        int result = 0;
        for(int i=0;i<nums.size();i++){

            if(i%2==0){
                auto it = lower_bound(allPrimes.begin(),allPrimes.end(),nums[i]);

                if(it == allPrimes.end()){
                    result += last_prime - nums[i];
                    continue;
                }

                result += *it - nums[i];
            }else{
                auto it = lower_bound(non_primes.begin(),non_primes.end(),nums[i]);

                result += *it - nums[i];
            }
            
        }

        return result;
    }
};
