class Solution {
public:
    
    
    int findGCD(vector<int>&numsDivide)
    {
        int gcd = numsDivide[0];
        
        for(int i=0;i<numsDivide.size();i++)
        {
            int val = numsDivide[i];
            
            while(val>0)
            {
                int temp = gcd%val;
                gcd = val;
                val = temp;
            }
        }
        
        return gcd;
    }
    
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int gcd = findGCD(numsDivide);
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(gcd%nums[i] ==0 )
                return i;
        }
        
        return -1;
    }
};
