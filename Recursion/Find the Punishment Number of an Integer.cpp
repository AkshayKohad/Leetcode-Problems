class Solution {
public:

    bool check(int val,int &i,int &sum)
    {
        if(val == 0)
        return false;


        if(sum + val == i)
        return true;

        int res = 0;
        int num = 10;
        while(val/num > 0)
        {
           sum = sum + val%num;
           bool flag = check(val/num,i,sum);
           if(flag == true)
           return true;
           sum = sum - val%num;

           num = num*10;

        }
 
          return false;
    }

    int punishmentNumber(int n) {
        
        int result = 0;
        // int sum= 0;
        for(int i=1;i<=n;i++)
        {
          int sum= 0;   
             if(check(i*i,i,sum))
             result = result + i*i;



        }

        return result;
    }
};
