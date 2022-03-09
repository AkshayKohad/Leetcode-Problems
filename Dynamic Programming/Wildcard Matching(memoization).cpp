class Solution {
public:
    bool solve(string &s,string &p,int n,int m,vector<vector<int>>&memo)
{
	if(n==0 && m==0)
	return 1;

   if(m==0)
	{
		return 0;
	}


 if(memo[n][m]!=-1)
  return memo[n][m];

	if(n==0)
	{
		if(m!=0)
		{
         if(p[m-1]=='*')
		 return memo[n][m] = solve(s,p,n,m-1,memo);

		 else
		 return memo[n][m] = 0;
		}
		
		return 0;
	}

	
 

	if(s[n-1]==p[m-1])
	{
		return memo[n][m] = solve(s,p,n-1,m-1,memo);
	}

	else{
		if(p[m-1]=='?')
		{
			return memo[n][m] = solve(s,p,n-1,m-1,memo);
		}

		else if(p[m-1]=='*')
		{
			return memo[n][m] = solve(s,p,n-1,m-1,memo) || solve(s,p,n-1,m,memo)||solve(s,p,n,m-1,memo);
		}

		else
		return memo[n][m]=0;
	}

	

}
    
    bool isMatch(string s, string p) {
        int n = s.length();
	int m = p.length();
	vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return solve(s,p,n,m,memo);
        
    }
};
