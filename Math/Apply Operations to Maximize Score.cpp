class Solution {
public:
    
    #define ll long long
    #define mod 1000000007
    

    ll prime_sieve[100001];
    ll count_prime[100001];

   static bool mycmp(pair<ll,ll>a,pair<ll,ll>b)
   {
       return a.first>b.first;
   }

   ll power(ll base, ll n)
   {
       if(n==0)
       return 1;

       if(n==1)
       return base;

       if(n&1)
       {
          
          ll ans = power(base,(n-1)/2);
          
          ll res = (ans*ans)%mod;

          return (res*base)%mod;
       }

       
          ll ans = power(base,n/2); 
          return (ans*ans)%mod;
       
   }
    
    void sieve()
    {
        for(ll i=0;i<=100000;i++)
        {
         prime_sieve[i]=0;
         count_prime[i]=0;
        }
        for(ll i=2;i<=100000;i++)
        {
            if(prime_sieve[i]!=0)
            {
                continue;
            }
            
            prime_sieve[i]=-1;
            count_prime[i]=1;
            
            for(ll j=2*i;j<=100000;j=j+i)
            {
                   count_prime[j]++;
                    prime_sieve[j] = 1;
                
            }
        }
    }
    
    int maximumScore(vector<int>& nums, int k) {
    
        
        sieve();
        
        ll n = nums.size();
        
        vector<ll>cnt_prime(n,0);
        
        for(ll i=0;i<n;i++)
        {
            if(nums[i]==1 || nums[i]==0)
                continue;
            
            cnt_prime[i] = count_prime[nums[i]];
        }
        
        
        
        vector<ll>left(n);
        
        vector<ll>right(n);
        
        stack<ll>st;
        
        for(ll i=0;i<n;i++)
        {
            while(st.empty()==false && cnt_prime[st.top()]<cnt_prime[i])
            {
                st.pop();
            }
            
            if(st.empty()==true)
            {
                left[i] = i;
            }
            else{
                left[i] = i-st.top()-1;
            }
            st.push(i);
        }
        
        stack<ll>st1;
        
        for(ll i=n-1;i>=0;i--)
        {
            while(st1.empty()==false && cnt_prime[st1.top()]<=cnt_prime[i])
            {
                st1.pop();
            }
            
            if(st1.empty()==true)
            {
                right[i] = n-1-i;
            }
            
            else{
                right[i] =  st1.top()-i-1;
            }
            st1.push(i);
        }
        
   
        
        vector<ll>subarray(n);
        
        for(ll i=0;i<n;i++)
        {
         
            subarray[i] = (left[i]*right[i])+(1*right[i])+(1*left[i]) + 1; 
        
        }
        
    
        
        vector<pair<ll,ll>>res;
        
        for(ll i=0;i<n;i++)
        {
            res.push_back({nums[i],subarray[i]});
        }
        
        sort(res.begin(),res.end(),mycmp);
        
      
        
        ll i=0;
        ll result = 1;
        while(k>0 && i<n)
        {
           
            if(k>=res[i].second)
            {
                result = (result*power(res[i].first,res[i].second))%mod;
                k = k - res[i].second;
            
            }
            else{
                 result = (result*power(res[i].first,k))%mod;
                k=0;
            }
            i++;
        }
        return result;
        
    }
};
