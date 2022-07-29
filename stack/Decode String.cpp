class Solution {
public:
    string decodeString(string s) {
        
        string ans;
        stack<string>characters;
        
        stack<int>values;
        
        int i = 0;
        
        while(i<s.length())
        {
            if(isdigit(s[i]))
            {
                string t;
                while(i<s.length() && isdigit(s[i]))
                {
                t.push_back(s[i]);
                i++;
                }
                
                int val = stoi(t);
                
                values.push(val);
            }
            
           else if(s[i]=='[')
            {
                characters.push("[");
                i++;
            }
            
            else if(isalpha(s[i])){
                string t;
                while(i<s.length() && isalpha(s[i]))
                {
                t.push_back(s[i]);
                    i++;
                }
               // cout<<t<<endl;
                characters.push(t);
            }
            
            else{
                string res;
                while(characters.empty()==false && characters.top()!="[")
                {
                    res = characters.top()+res;
                    
                    characters.pop();
                }
              //  cout<<res<<endl;
                characters.pop();
                
                
                if(characters.empty()==false)
                {
                 int freq =  values.top();
                    values.pop();
                    
                    string result = "";
                    
                    for(int i=1;i<=freq;i++)
                        result += res;
                    
                 //   cout<<result;
               
                 characters.push(result);
                    
                    
                }
                
                else{
                    int freq =  values.top();
                    values.pop();
                    
                    string result = "";
                    
                    for(int i=1;i<=freq;i++)
                        result += res;
                    
                    characters.push(result);
                    
                }
                
                i++;
            }
        }
        
        
        while(characters.empty()==false)
        {
            ans = characters.top() + ans;
            
            characters.pop();
        }
        
        return ans;
    }
};
