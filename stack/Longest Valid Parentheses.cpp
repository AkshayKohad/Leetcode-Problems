
//https://www.youtube.com/watch?v=qC5DGX0CPFA


class Solution {
public:
    
    
    
    int longestValidParentheses(string s) {
    
        
        //charecter stack;
        stack<char>character;
        
        // index stack
        stack<int>index;
        
        index.push(-1);
        int n = s.length();
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                character.push('(');
                index.push(i);
            }
            
            else{
                // '(' are present in stack 
                if(character.empty()==false)
                {
                    index.pop();
                    character.pop();
                    
                    res  = max(res,i-index.top());
                }
                
                
                // '(' not present in stack
                else{
                    index.push(i);
                }
                
                
            }
        }
        
        return res;
    }
};
