class Solution {
public:
    
    bool solve(string s,string p,int i,int j, vector<vector<int>>&memo)
    {
        if(i==0 && j==0)
            return true;
        
        if(i==0)
        {
            while(j>0)
            {
                if(p[j-1]=='*')
                j=j-2;
                
                
                
                else
                    return false;
            }
//             if(j==0)
//                 return true;
            
            return true;
            
            
        }
        
        if(j==0)
            return false;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        
        if(p[j-1]=='*')
        {
            if(p[j-2]==s[i-1] || p[j-2]=='.')
        return memo[i][j] = solve(s,p,i-1,j,memo) || solve(s,p,i,j-2,memo);
            
            
            else{
                return memo[i][j] = solve(s,p,i,j-2,memo);
            }
        }
        else if(p[j-1]=='.')
            return memo[i][j] = solve(s,p,i-1,j-1,memo);
        
        else if(p[j-1]==s[i-1])
            return memo[i][j] = solve(s,p,i-1,j-1,memo);
        
       // else if(p[j-1]!=s[i-1])
            return memo[i][j] = false;
        
      
    }
    bool isMatch(string s, string p) {
        
        
        vector<vector<int>>memo(s.length()+1,vector<int>(p.length()+1,-1));
       return solve(s,p,s.length(),p.length(),memo);
    }
};
