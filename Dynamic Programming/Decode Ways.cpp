class Solution {
public:
    
    int solve(int i,string s,string k,unordered_map<int,char>mp,vector<int>&memo)
    {
        if(i>=s.length())
        {
                return 1;
        }
        
        if(s[i]=='0')
            return 0;
        
        if(memo[i]!=-1)
            return memo[i];
        
        int res = 0;
        for(int j=i;j<s.length();j++)
        {
            
            string t = s.substr(i,j-i+1);
            
            int r = stoi(t);
            
            if(r>26) break;
            
            
            char ch = mp[r];
            
            k.push_back(ch);
            
            res += solve(j+1,s,k,mp,memo);
            
            k.pop_back();
            
            
        }
        
        return memo[i] = res;
    }
    
    int numDecodings(string s) {
        
        unordered_map<int,char>mp;
        
        for(int i=0;i<26;i++)
        {
            char ch = 'a' + i;
            
            mp[i+1] = ch;
        }
        
        
        string k;
        
        int n = s.length();
        vector<int>memo(n,-1);
       return solve(0,s,k,mp,memo);
        
       
    }
};
