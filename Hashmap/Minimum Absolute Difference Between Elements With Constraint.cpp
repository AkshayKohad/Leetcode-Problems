class Solution {
public:
    #define ll long long
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        
      
        set<int>s;
        int result = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
         s.insert(nums[i]);
            
          if(i-x>=0)
          {
              auto it = s.lower_bound(nums[i-x]);
              
                auto it2 = prev(it);
              
              if(it!=s.end())
              {
                   int val = *(it);
                  result = min(result,abs(nums[i-x]-val));
              }
              
              if(it2!=s.end())
              {
                   auto it3 = prev(it);
                  int val2 = *it3;
                  
                   result = min(result,abs(nums[i-x]-val2));
              }
              
              
          }
            else{
                break;
            }
        }
        
      
        
        return result;
    }
};
