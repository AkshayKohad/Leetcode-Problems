class Solution {
public:
    int singleNumber(vector<int>& nums) {

     vector<int>bits_count(33,0);

     int count_negative_bit = 0;

     for(int i=0;i<nums.size();i++)
     {
         long long int val = nums[i];
         if(val<0)
         {
             count_negative_bit++;
             val=val*(-1);
         }

       
         for(int j=0;j<=32;j++)
         {
            long long int bit = ((val>>j) & (1));

            if(bit>0)
            {
               bits_count[j]++;
            }

            
         }
     }

   long long int res = 0;
     for(int i=0;i<=32;i++)
     {
           if(bits_count[i]!=0 && bits_count[i]%3!=0)
           {
               res = res + pow(2,i);
           }
     }


  if(count_negative_bit%3!=0)
  {
      res = res*(-1);
  }

  return res;
    }
};
