class Solution {
public:

   
    int countVowelStrings(int n) {
        
        int  a,e,i,o,u;
         a = e = i = o = u = 1;

       if(n==1)
       return a+e+i+o+u;

        n = n-1;
       while(n--)
       {
           o += u;
           i += o;
           e += i;
           a += e;
       }

       return a+e+i+o+u;


    }
};
