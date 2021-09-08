class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return 1;
        int i=0;
        int count=0,max=0;
        int a[128]={0};
        int b[128];
        while(s[i]!='\0')
        {
            
           if(a[s[i]]>=1)
           {
             for(int j=0;j<=127;j++)
                 a[j]=0;
               i=b[s[i]]+1;
               
               if(max<count)
                   max=count;
               count=0;
           }
            else if(a[s[i]]==0) 
            {
                b[s[i]]=i;
              a[s[i]]++;
                count++;
                i++;
            }
            
        }
            
        
        if(count>max)
            max=count;
         return max;   
    }
};
