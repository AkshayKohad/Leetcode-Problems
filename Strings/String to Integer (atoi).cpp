class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
        
        while(i<s.length() && s[i]==' ')
            i++;
        
      
        
        
        bool is_neg = false;
        if(i<s.length() && s[i]=='-')
        {
            is_neg = true;
            i++;
        }
        
        else if(i<s.length() && s[i]=='+')
            i++;
        
            
        
        int ans = 0;
        int j = i;
        while(j<s.length() && isdigit(s[j]))
        {
            int val = s[j] - '0';
            
            if((INT_MAX-val)/10<ans)
            {
                if(is_neg)
                    return INT_MIN;
                else
                return INT_MAX;
            }
            
            ans = ans*10 + val;
            j++;
        }
        
        if(ans==0)
            return 0;
        
        if(is_neg)
            return -ans;
        
        return ans;
        
        return 0;
    }
};
