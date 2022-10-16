class Solution {
public:
    
    
    int solve(int i,vector<int>& jobDifficulty,int &n,int d,vector<vector<int>>&memo)
    {
        if(i==n && d==0)
            return 0;
        
        if(i==n || d==0)
            return -1;
        
        if(memo[i][d]!=-2)
            return memo[i][d];
        
        
        int res = INT_MAX;
        
        int maxi = -1;
        
        for(int j=i;j<n;j++)
        {
            maxi = max(jobDifficulty[j],maxi); 
                
              int check = solve(j+1,jobDifficulty,n,d-1,memo);
            
            
            if(check!=-1)
            {
                int ans = maxi + check;
                
                res = min(res,ans);
            }
            
        }
        
        if(res==INT_MAX)
            return memo[i][d] = -1;
            
        
        return memo[i][d] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
       
        
        int n = jobDifficulty.size();
        
        
        if(n<d)
            return -1;
        
        
        vector<vector<int>>memo(n+1,vector<int>(d+1,-2));
        return solve(0,jobDifficulty,n,d,memo);
        
        
            
    }
};
