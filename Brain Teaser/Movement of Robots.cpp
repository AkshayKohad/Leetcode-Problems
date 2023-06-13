class Solution {
public:
    
  
    #define ll long long
    int sumDistance(vector<int>& nums, string s, int d) {
        
        const int mod = 1000000007;
        vector<ll>result;
        
        ll n = nums.size();
        
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                result.push_back((nums[i] + d));
            }
            
            else{
                result.push_back((nums[i] - d));
            }
        }
        
       
        sort(result.begin(),result.end());
       
        ll answer = 0;
        ll prefsum = 0;
        for(ll i=0;i<n;i++)
        {
            answer = (answer + i*result[i] - prefsum)%mod;
            prefsum = (prefsum + result[i])%mod;
        }
        
     
     
        return (int)answer;
    }
};
