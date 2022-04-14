class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=1;
        int close=0;
        string a;
        for(int i=1;i<s.size();i++)
        {
           
             if(s[i]=='(' )
            {
                if(open==close)
                    open++;
                else{
                open++;
                a.push_back(s[i]);
                }
            }
            else if(s[i]==')' && open!=close)
            {
                if(open==close+1)
                {
                    close++;
                }
                else{
                    close++;
                    a.push_back(s[i]);
                }
            }
            
        }
        return a;
    }
};
