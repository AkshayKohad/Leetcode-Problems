class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     
        int n = nums.size();
        unordered_map<int,int>m;
        m[0] = -1;
        
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            
            int remainder = sum%k;
            if(m.find(remainder)==m.end())
            {
                m[remainder] = i;
            }
            
            else{
                if(i-m[remainder]>1)
                    return true;
            }
            
            
        }
        
        return false;
        
    }
};
