class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        

        // nums[i] AND (nums[i] XOR x) cannot increase the value of nums[i], so if we have 0 at 
        //ith bit position we can't change it 
        // if we have 1 at ith position we can change it if total xor of it will give 0 and we 
        //want 1.
        // so just check if across all elements if 1 is present at ith bit position if yes 
        // add the value pow(2,i) to result
        // return result

       int n = nums.size();

        int result = 0;
        for(int i=31;i>=0;i--)
        {
            bool one_present = false;
          for(int j=0;j<n;j++)
          {
              int bit = (nums[j]>>i) & 1;

              if(bit==1)
              {
                  one_present = true;
                  break;
              } 
          }

          if(one_present)
          {
              result = result + pow(2,i);
          }

        }

        return result;
    }
};

