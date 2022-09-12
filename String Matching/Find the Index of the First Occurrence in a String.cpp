class Solution {
public:
    
    void fill_lps(vector<int>&lps,string &needle,int &m)
    {
        int len = 0;
        int i = 1;
        while(i<m)
        {
            if(needle[i]==needle[len])
            {
                len++;
                lps[i] = len;
                i++;
                
            }
            
            else{
                if(len==0)
                {
                    lps[i] = 0;
                    i++;
                }
                
                else{
                    len = lps[len-1];
                }
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        
        int m = needle.length();
        
        
        vector<int>lps(m,0);
        fill_lps(lps,needle,m);
        
        
        
        
        int i=0;
        int j=0;
        
        
        while((n-i)>=(m-j))
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            
            if(j==m)
            {
                return i-j;
            }
            
            else if(i<n && haystack[i]!=needle[j])
            {
                if(j==0)
                {
                    i = i+1;
                }
                
                else{
                    j = lps[j-1];
                }
                
            }
        }
        
        return -1;
    }
};
