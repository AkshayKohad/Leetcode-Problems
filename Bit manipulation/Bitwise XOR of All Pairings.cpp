class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
     
        int ans = 0;
        
        int n = nums1.size();
        
        int m = nums2.size();
        
        if(n%2==1)
        {
            for(auto val : nums2)
            {
              ans = ans ^ val;   
            }
        }
        
        if(m%2==1)
        {
           for(auto val : nums1)
           {
               ans = ans ^ val;
           }
        }
        
        return ans;
    }
};
