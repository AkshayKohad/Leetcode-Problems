class Solution {
public:
    
    bool isPalindrome(string res)
    {
        int i=0;
        int j=res.length()-1;
        
        while(i<j)
        {
            if(res[i]!=res[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
     
        for(int i=2;i<=n-2;i++)
        {
            int temp = n;
            
            string res;
            
            while(temp)
            {
                res += to_string(temp%i);
                
                temp = temp/i;
            }
            
            if(!isPalindrome(res)) return false;
        }
        
        return true;
    }
};
