class Solution {
public:
    
    #define ll long long
    
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        ll n = nums.size();
        
        for(ll i=0;i<n;i++)
        {
            nums[i] = nums[i]%modulo;
        }
        
        vector<ll>prefix(n,0);
        
        if(nums[0]==k)
            prefix[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1];
            
            if(nums[i]==k)
                prefix[i]+=1;
            
        }
        
//         for(ll i=0;i<n;i++)
//             cout<<prefix[i]<<" ";
        
//         cout<<endl;
        
        //ll i=0;
         ll result = 0;
         ll ans = 0;
             
      unordered_map<ll,ll>mp;
        
        mp[0] = 1;
        
      for(ll i=0;i<n;i++)
      {
         // if(prefix[i]%modulo==k) 
         //  result++;
             
         ll res = (prefix[i]-k+modulo)%modulo;
         
          result += mp[res];
          
          mp[prefix[i]%modulo]++;
      }
        
        return result;
    }
};
