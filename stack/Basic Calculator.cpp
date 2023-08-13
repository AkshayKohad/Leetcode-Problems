class Solution {
public:

  int find_priority_val(char ch)
  {
      if(ch == '+' || ch == '-') return 1;

      if(ch == '*' || ch=='/') return 2;

      return 0;
  }

  int evaluation_postfix(string postfix)
  {

      stack<int>st;

      int i=0;
      int n = postfix.length();
      while(i<n)
      {
          if(postfix[i]!='+' && postfix[i]!='-')
          {
              
              int k = postfix[i]-'0';
              i++;
              while(i<n && postfix[i]=='#')
              {
                  i++;
                  k = k*10 + (postfix[i]-'0');
                  
                  i++;
              }

              
              st.push(k);
          }
          else{
              int val1 = st.top();
              st.pop();
              int val2 = st.top();
               st.pop();

             if(postfix[i]=='+')
              st.push(val2+val1);

              else
              st.push(val2-val1);

              i++;
          }
      }
      int res = st.top();

      return res;
     return 0;
  }
  
  string convert_infix_postfix(string s)
  {
      stack<char>st;
      string postfix;
      int i=0;
      int n = s.length();

     while(i<n)
      {
          if(s[i]==' '){i++; continue;}

         if(s[i]=='+' || s[i]=='-')
         {
           
            if(postfix.length()==0)
            {
                postfix.push_back('0');
            }
            
          

          while(st.empty()==false && find_priority_val(s[i]) <= find_priority_val(st.top()) )
           {
               postfix.push_back(st.top());
               st.pop();
           }
            st.push(s[i]);

            i++;
         }

         else if(s[i]=='(')
         {
          st.push(s[i]);
          i++;
          
          while(i<n && s[i]==' ')
          i++;
          if(i<n && (s[i]=='+' || s[i]=='-'))
          {
              postfix.push_back('0');
          }
         }

          else if(s[i]==')')
          {
              while(st.empty()==false && st.top()!='(')
              {
                  postfix.push_back(st.top());
                  st.pop();
              }
              st.pop();
              i++;
          }

          else{
              while(i<n && s[i]!='+' && s[i]!='-' && s[i]!='(' && s[i]!=')' && s[i]!=' ')
              {
              postfix.push_back(s[i]);
              postfix.push_back('#');
              i++;
              }
              postfix.pop_back();
          }

      }

  while(st.empty()==false)
  {
      postfix.push_back(st.top());
      st.pop();
  }

  
  return postfix;

  }
    int calculate(string s) {
        
       // return 0;
        string postfix = convert_infix_postfix(s);
         cout<<postfix<<endl;
     //    return 0; 
        return evaluation_postfix(postfix);

    }
};
