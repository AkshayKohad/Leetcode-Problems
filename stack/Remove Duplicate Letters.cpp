class Solution {
public:
    string removeDuplicateLetters(string s) {
           int n = s.length();
        
        stack<int>st;
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]] = i;
        }
        
        unordered_set<char>se;
        
        for(int i=0;i<n;i++)
        {
            if(se.find(s[i])!=se.end())
            {
               continue;
            }
            
            
            
            while(st.empty()==false && s[st.top()]>=s[i] && mp[s[st.top()]] >= i )
            {
                 se.erase(s[st.top()]);
                st.pop();
                
            }
            
            
            
                st.push(i);
                se.insert(s[i]);
            
            
            
        }
        
        string res;
        
        while(st.empty()==false)
        {
            res.push_back(s[st.top()]);
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        
        return res;   
    }
};
