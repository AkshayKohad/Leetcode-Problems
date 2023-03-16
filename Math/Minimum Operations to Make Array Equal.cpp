class Solution {
public:
    int minOperations(int n) {
        int result = 0;
         if(n%2==1)
         {
             int mid = n/2;

            int val = 2*mid+1;

            for(int i=1;i<val;i=i+2)
            {
                result += val-i;
            }
         }

         else{
             int mid1 = n/2;
             int mid2 = n/2 -1;

           int val1 = 2*mid1+1;
           int val2 = 2*mid2+1;

           int val = (val1+val2)/2;

           for(int i=1;i<val;i=i+2)
           {
               result += val-i;
           }
         }

           

            // sum of ap of n terms where a=1 d=2;

            return result;
        


    }
};
