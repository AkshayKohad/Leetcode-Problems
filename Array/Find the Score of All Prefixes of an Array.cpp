class Solution {
public:
    
    #define ll long long 
    
    vector<long long> findPrefixScore(vector<int>& nums) {
        
        
        
        int n = nums.size();
        
        vector<ll>maxi(n);
        
        vector<ll>conver(n);
        
        int val = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            val = max(val,nums[i]);
            
            maxi[i] = val;
            
            conver[i] = maxi[i] + nums[i];
        }
        
        vector<ll>prefix_conver(n);
        prefix_conver[0] = conver[0];
        
        for(int i=1;i<n;i++)
        {
            prefix_conver[i] = prefix_conver[i-1] + conver[i];
        }
        
        return prefix_conver;
        
    }
};
