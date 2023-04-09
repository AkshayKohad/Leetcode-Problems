class Solution {
public:
    #define ll long long
    
    vector<long long> distance(vector<int>& nums) {
        
       //occurence of each element
        unordered_map<ll,ll>ele_size;
        
       //prefix_sum of indexes same element value
       unordered_map<ll,ll>prefix;
       
       // prefix_sum mapped according to indexes -> prefix_sum 
       unordered_map<ll,ll>value;
        
        
        for(int i=0;i<nums.size();i++)
        {
          
            ele_size[nums[i]]++;
            
            prefix[nums[i]] = prefix[nums[i]] + i;
            
            value[i] = prefix[nums[i]];

        }
          
        vector<ll>result;
        
        unordered_map<ll,ll>fre;

        for(int i=0;i<nums.size();i++)
        {
           
          
            ll prefix_sum = prefix[nums[i]];
            ll ans = value[i];
            
            ll rank = fre[nums[i]];
            fre[nums[i]]++;
            
           
            
            ll answer = rank*i - ans + i  + prefix_sum - ans - (ele_size[nums[i]]-rank-1)*i;
            
            
            result.push_back(answer);
                
        }
        
        return result;
        
    }
};
