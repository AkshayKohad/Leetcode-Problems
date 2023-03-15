class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
      int n = nums.size();

      int result = 0;
        for(int i=0;i<n;i++)
        {
            int val = nums[i];
            int count_divisors = 0;
            int cur_result = 0;
            for(int j=1;j*j<=val;j++)
            {
                if(val%j==0)
                {
                    int k = val/j;

                    if(k!=j)
                    {
                    count_divisors += 2;
                    cur_result += val/j + j;
                    }
                    else{
                        count_divisors += 1;
                        cur_result = k;
                    }
                }
            }

            if(count_divisors==4)
            {
                result += cur_result;
            }
        }

        return result;
    }
};
