class Solution {
public:
    
    
    bool isSafe(string k,set<string>&st)
    {
        if(st.find(k)!=st.end())
            return true;
        
        return false;
    }
    bool solve(int i,string s,set<string>&st,int n,vector<int>&memo)
    {
             if(i==n)
             {
                 return true;
             }
        
          if(memo[i]!=-1)
              return memo[i];
        
        for(int j=i;j<n;j++)
        {
            if(isSafe(s.substr(i,j-i+1),st))
            {
                if(solve(j+1,s,st,n,memo))
                {
                    memo[i] = 1;
                    return true;
                }
                
            }
        }
        memo[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
     
        
        set<string>st;
        
        for(int i=0;i<wordDict.size();i++)
        {
           st.insert(wordDict[i]);   
        }
        int n = s.length();
        vector<int>memo(n,-1);
        return solve(0,s,st,n,memo);
    }
};
