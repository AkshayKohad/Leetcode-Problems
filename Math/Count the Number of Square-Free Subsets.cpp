class Solution {
public:
    
    #define mod 1000000007
    
    vector<int>primes = {2,3,5,7,11,13,17,19,23,29};
    
    #define ll long long
    
    
    int ConvertToMask(ll val)
    {
        int mask = 0;
        
        for(int i=0;i<primes.size();i++)
        {
            if(val%primes[i]==0)
            {
                mask |= (1<<i);
            }
        }
        
        return mask;
    }
    
    ll  ConvertFromMask(int mask)
    {
        ll result = 1;
        
        for(int i=0;i<primes.size();i++)
        {
            if((mask & (1<<i))!=0)
            {
                result = (result * primes[i]);
            }
        }
        
        return result;
    }
    int CountSubsets(int i,int mask,vector<int>&a,vector<vector<ll>>&memo,int &n)
    {
        if(mask==0)
            return 1;
        if(i==n)
            return 0;
        
        
        if(memo[i][mask]!=-1)
            return memo[i][mask];
        
        ll val = ConvertFromMask(mask);
        
        ll ans = 0;
        
        ans = (ans + CountSubsets(i+1,mask,a,memo,n))%mod;
        
        if(val%a[i]==0)
        {
            ans = (ans + CountSubsets(i+1,ConvertToMask(val/a[i]),a,memo,n))%mod;
        }
        
        return memo[i][mask] = ans;
    }
        
    int squareFreeSubsets(vector<int>& nums) {
        
        vector<int>nums_without_1;
        
        int ones  = 0;
        for(auto k:nums)
        {
            if(k==1)
            {
                ones++;
            }
            else{
                nums_without_1.push_back(k);
            }
        }
        
        int n = nums_without_1.size();
        
        vector<vector<ll>>memo(n,vector<ll>(1025,-1));
        
        
        ll non_empty_1_subset = 1;
        
        while(ones--)
        {
            non_empty_1_subset = (non_empty_1_subset*2)%mod;
        }
        
        
        non_empty_1_subset = (non_empty_1_subset-1+mod)%mod;
        
        
        ll non_empty_other_subset = 0;
        
        for(int mask = 1;mask<=1024;mask++)
        {
            non_empty_other_subset = (non_empty_other_subset + CountSubsets(0,mask,nums_without_1,memo,n))%mod;
        }
        
        // all cobinations of 1 individually + combinations without 1
        ll result = (non_empty_other_subset + non_empty_1_subset)%mod;
        
        // each combinations_of_1 with each other_combinations_without_1
        result = (result + (non_empty_other_subset*non_empty_1_subset)%mod)%mod;
        
        
        return result;
        
    }
};
