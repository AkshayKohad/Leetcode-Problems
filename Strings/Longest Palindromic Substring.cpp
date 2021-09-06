class Solution {
public:
    string longestPalindrome(string s) {
        
        int max=1;
        int index1=0;
        int index2=0;
        for(int i=0;i<s.length()-1;i++)
        {
            int j=i;
            int k=i;
            
           while(j>=0 && k<s.length() && s[j]==s[k])
           {
               j--;
               k++;
           }
            j++;
            k--;
            
            if(max<k-j+1)
            {
                max=k-j+1;
                index1=j;
                index2=k;
            }
            
            
            if(s[i]==s[i+1])
            {
                j=i;
                k=i+1;
                
                while(j>=0 && k<s.length() && s[j]==s[k])
                {
                    j--;
                    k++;
                }
                
                 j++;
                 k--;
            
            if(max<k-j+1)
            {
                max=k-j+1;
                index1=j;
                index2=k;
            }
                
            }
        }
        
        string a;
        for(int i = index1;i<=index2;i++)
        {
            a = a + s[i];
        }
        return a;
    }
};
