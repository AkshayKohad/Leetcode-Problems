class Solution {
public:

    bool check(long long l,long long r,long long n)
    {
        while(l<=r)
        {
            long long mid = (l+r)/2;

            if(mid*mid == n)
            return true;

            else if(mid*mid>n)
            {
                r = mid-1;
            }
  
            else{
                l = mid+1;
            }

        }

        return false;
    }

    bool judgeSquareSum(int c) {
        
        for(long long a = 0;a*a <=c ;a++)
        {
            long long b = c - a*a;

            if(check(0,b,b))
            return true; 
        }

        return false;
    }
};
