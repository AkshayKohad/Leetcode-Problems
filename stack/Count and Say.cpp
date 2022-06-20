class Solution {
public:
    
    
    void solve(int n,string &s,stack<int>&st)
    {
        if(n==1)
        {
            st.push(1);
            return;
        }
        
        solve(n-1,s,st);
        vector<int>a;
        while(st.empty()==false)
        {
            int count = 1;
            int val = st.top();
            st.pop();
            while(st.empty()==false && val==st.top())
            {
                count++;
                st.pop();
            }
            
            a.push_back(count);
            a.push_back(val);
            
        }
        
        for(int i=a.size()-1;i>=0;i--)
        {
            st.push(a[i]);
        }
        
        return;
    }
    string countAndSay(int n) {
        
        
        if(n==1)
            return "1";
        
        stack<int>st;
        string s;
        
        solve(n,s,st);
        
        while(st.empty()==false)
        {
            char ch = st.top()+48;
            
           // cout<<st.top()<<" ";
            s.push_back(ch);
            st.pop();
        }
        
       return s;
       // return " ";
    }
};
