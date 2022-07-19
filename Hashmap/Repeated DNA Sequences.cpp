class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        if(s.length()<=10)
        return {};
        
        
        string t = s.substr(0,10);
        
        unordered_set<string>st;
        unordered_set<string>res;
        
        
        vector<string>ans;
        st.insert(t);
        
        for(int i=10;i<s.length();i++)
        {
            t.erase(0,1);
            t.push_back(s[i]);
            
            if(st.find(t)!=st.end())
            {
                if(res.find(t)==res.end())
                {
                    res.insert(t);
                    ans.push_back(t);
                }
                
            }
            
            else{
                st.insert(t);
            }
        }
        
        return ans;
    }
};
