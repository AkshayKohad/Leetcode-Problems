class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        
        if(n==1)
            return "";
        
        
            int index = n/2;
            
            
            int flag = 0;
            for(int i=0;i<=index-1;i++)
            {
                if(palindrome[i]!='a')
                {
                    palindrome[i] = 'a';
                    flag=1;
                    break;
                }
            }
            
            if(flag==1) return palindrome;
            
            palindrome[n-1] = 'b';
                
            return palindrome;
            
    }
};
