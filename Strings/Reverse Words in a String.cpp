class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        int i=0;
        
        while(i<n && s[i]==' ')
            i++;
        int j = n-1;
        
        while(j>=0 && s[j]==' ')
            j--;
        
        string res = "";
        while(i<=j)
        {
            string t = "";
            
            while(i<=j && s[i]!=' ')
            {
                t.push_back(s[i]);
                i++;
            }
            
            while(i<=j && s[i]==' ')
            i++;
           
            if(res.length()==0)
            {
                res = t;
            }
            
            
            else if(res.length()!=0)
            {
                res = t + " " + res;
            }
        }
        
      
        return res;
    }
};
