class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int total = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,nums[i]);
            
            mini = min(mini,nums[i]);
            
            total += nums[i];
        }
        if(maxi<0)
            return maxi;
       
        int sum=0;
        // for maximum subarray
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
             if(sum<0)
                sum=0;
            
            if(sum>maxi)
                maxi=sum;
           
    
        }
      //  cout<<maxi<<endl;
         sum = 0;
      if(mini<0)
      {
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
             if(sum>0)
            {
                sum=0;
               
            }
            
            if(sum<mini)
            {
                mini = sum;
               
            }   
            
           
        }
      }
       // cout<<mini<<endl;
        
        int res;
        
        res= max(total-mini,maxi);
        
        
        return res;
    }
};
