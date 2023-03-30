class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int>s;
        
        int val = nums[0];
        for(int i=0;i<n;i++)
        {
          s.insert(nums[i]);
        }
        
        for(int i=0;i<31;i++)
        {
            int val = pow(2,i);
            
            if(s.find(val)==s.end())
            {
                return val;
            }
        }
        
        return -1;
        
    }
};
