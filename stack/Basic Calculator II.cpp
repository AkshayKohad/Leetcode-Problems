class Solution {
public:
   
   int priority_symbols(char ch)
   {
       if(ch=='+' || ch=='-')
       return 1;

       if(ch=='*' || ch=='/')
       return 2;

       return 0;
   }

   int evaluate_postfix(string postfix)
   {
        stack<int>st;

        int i=0;
        int n = postfix.length();

         while(i<n)
         {
            if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
            {
                 int val = st.top();
                 st.pop();
                 int val2 = st.top();
                 st.pop();

                 if(postfix[i]=='+')
                 {
                    st.push(val2+val);
                 }
                 else if(postfix[i]=='-')
                 {
                    st.push(val2-val);
                 }
                 else if(postfix[i]=='*')
                 {
                    st.push(val2*val);
                 }
                 else if(postfix[i]=='/')
                 {
                    st.push(val2/val);
                 }

                 i++;
            }

            else{
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
         }

         return st.top();
   }
     
    string convert_string_postfix(string s)
    {
        string postfix;
        stack<char>st;

         int i=0;
         int n = s.length();
        while(i<n)
        {
            if(s[i]==' '){
                i++;
                continue;
            }
           if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
           {
              while(st.empty()==false && (priority_symbols(s[i]) <= priority_symbols(st.top())))
              {
                  postfix.push_back(st.top());
                  st.pop();
              }

              st.push(s[i]);
              i++;
           }

           else{
               postfix.push_back(s[i]);
               i++;
               while(i<n && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!=' ')
               {
                   postfix.push_back('#');
                   postfix.push_back(s[i]);
                   i++;
               }
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

      string postfix = convert_string_postfix(s);
      cout<<postfix<<endl;
      return evaluate_postfix(postfix);
        return 0;
    }
};
