class Solution {
public:
    
    void solve(int i,string s,set<string>st,vector<string>&res,string ans)
    {
        if(i==s.length())
        {
            //cout<<ans<<endl;
            ans.pop_back();
            
            
            res.push_back(ans);
            
            ans.push_back(' ');
            return;
        }
        
        for(int j=i;j<s.length();j++)
        {
            string t = s.substr(i,j-i+1);
            
            if(st.find(t)==st.end())
                continue;
            
          
            string f = ans;
            
            t += " ";
           ans += t;
            
            solve(j+1,s,st,res,ans);
            
        
            ans.erase();
            ans = f;
            
            
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        set<string>st;
        
        for(auto k:wordDict)
        {
            st.insert(k);
        }
        
        vector<string>res;
        string ans;
        solve(0,s,st,res,ans);
        
        return res;
    }
};
