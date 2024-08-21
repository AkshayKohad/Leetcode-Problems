class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>even_sum(n);
        vector<int>odd_sum(n);
      
        even_sum[0] = nums[0];
        odd_sum[0] = 0;

        for(int i=1;i<nums.size();i++)
        {
             if(i%2==0)
             {
                even_sum[i]+=even_sum[i-1]+nums[i];
                odd_sum[i]=odd_sum[i-1];
             }
             else{
                even_sum[i]=even_sum[i-1];
                odd_sum[i]=odd_sum[i-1]+nums[i];
             }
        }

        int res = 0;

        for(int i=0;i<n;i++)
        {
            
                int e_prev_sum=0;
                int e_next_sum=0;

                if(i-1>=0)
                {
                    e_prev_sum = even_sum[i-1];
                }
                
                e_next_sum = odd_sum[n-1]-odd_sum[i];
                
                int e_sum =  e_prev_sum + e_next_sum;


                int o_prev_sum=0;
                int o_next_sum=0;

                if(i-1>=0)
                {
                    o_prev_sum = odd_sum[i-1];
                }
                
                o_next_sum = even_sum[n-1]-even_sum[i];
                
                int o_sum =  o_prev_sum + o_next_sum;

                if(o_sum==e_sum)
                res++;
            
        }

        return res;
    }
};
