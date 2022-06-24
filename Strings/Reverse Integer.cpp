class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while(x!=0)
        {
            int remainder = x%10;
            x = x/10;
            
            
            //2147483647 -> INT_MAX that's why if rev == INT_MAX and
            //remainder more than 7 that means more than INT_MAX
          if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && remainder > 7)) 
              return 0;
              
            //-2147483648 -> INT_MIN  that's why if rev == INT_MIN/10 and 
            //remainder less than -8, that means less than INT_MIN
            
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && remainder < -8))
                return 0;
            
            
            //NOTE one thing we cannot do rev > (INT_MAX-remainder)/10  or 
            // rev < (INT_MIN-remainder)/10 because if remainder < 0 it might 
            //overflow INT_MAX and if remainder > 0 it might overflow INT_MIN
            
            rev = rev*10 + remainder;
        }
        
        return rev;
    }
};
