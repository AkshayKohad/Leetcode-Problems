class Solution {
public:
    
    #define MOD 1000000007
    
    int solve(int i,int color1,int color2,int color3,int &n,vector<vector<vector<vector<int>>>>&memo)
    {
        if(i==n)
            return 1;
        
        if(memo[i][color1][color2][color3]!=-1)
            return memo[i][color1][color2][color3];
        
        
        
        int res = 0;
        
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                for(int l=1;l<=3;l++)
                {
                    if(j!=color1 && k!=color2 && l!=color3 && j!=k && k!=l)
                    {
                      res = (res+solve(i+1,j,k,l,n,memo))%MOD;   
                    }
                }
            }
        }
        
        return memo[i][color1][color2][color3] = res;
    }
    int numOfWays(int n) {
        
        vector<vector<vector<vector<int>>>>memo(n+1,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        
        return solve(0,0,0,0,n,memo);
        
    }
};
