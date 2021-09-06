class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        
        int max=1;
        int index1=0;
        int index2=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
         }
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                if(flag==0)
                {
                    if(max<(i+1)-i+1)
                    {
                        max=(i+1)-i+1;
                        index1=i;
                        index2=i+1;
                        flag=1;
                    }
                }
            }
            else
                dp[i][i+1]=0;
         }
        
      for(int gap=0;gap<n;gap++)
      {
          //int k=j;
          for(int i=0;i+gap<n;i++)
          {
//               if(k>=n)
//                   break;
              
             // cout<<"("<<i<<","<<k<<") ";
              //k++;
              if(gap==0 || gap==1)
                  continue;
              
              if(s[i]==s[i+gap] && dp[i+1][i+gap-1])
              {
                  dp[i][i+gap]=1;
                  if(max<(i+gap)-i+1)
                  {
                      max = (i+gap)-i+1;
                      index1=i;
                      index2=i+gap;
                  }
              }
              
              else
                  dp[i][i+gap]=0;
              
              
          }
          //cout<<endl;
       }        
        string a;
        for(int i=index1;i<=index2;i++)
        {
            a = a+s[i];
        }
        
        return a;
    }
};
