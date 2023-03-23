class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size();
        vector<int>prefix_xor(n);

        prefix_xor[0] = nums[0];
        for(int i=1;i<n;i++)
        {
          prefix_xor[i] = prefix_xor[i-1] ^ nums[i];
        }


        vector<int>result;

        for(int i=n-1;i>=0;i--)
        {
            int val = prefix_xor[i];
            int ans = 0;
           for(int j=0;j<maximumBit;j++)
           {
               int bit = (val>>j) & 1;

               if(bit==0)
               {
                  ans += pow(2,j);
               }
               
           }

           result.push_back(ans);
        }

        return result;
    }
};
