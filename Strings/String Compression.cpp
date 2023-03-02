class Solution {
public:

    int digit_len(int count)
    {
        if(count==1)
        {
            return 0;
        }
        else if(count>1 && count<=9)
        {
            return 1;
        }
        else if(count>=10 && count<100)
        {
            return 2;
        }
        else if(count>=100 && count<1000)
        {
            return 3;
        }

        else{
            return 4;
        }



    }
    int compress(vector<char>& a) {

     int n = a.size();

      int i=0;
      int j=0;
      int res_lenght = 0;
      string res;
      while(j<n)
      {
          int count = 0;
        if(j<n && a[i]==a[j])
        {
        while(j<n && a[i]==a[j])
        {
            j++;
            count++;
        }
        res.push_back(a[i]);
       
        if(count>1)
        res = res + to_string(count);

         int len = digit_len(count);
         i=j;
        
         res_lenght += len+1;
        }

        

      }

      a.clear();
      for(int k=0;k<res.length();k++)
      {
        a.push_back(res[k]);
      }

      cout<<res_lenght;
      return res_lenght;   
    }
};
