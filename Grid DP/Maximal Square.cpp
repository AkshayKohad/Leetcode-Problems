class Solution {
public:

   
    int maximalSquare(vector<vector<char>>& matrix) {
         
         int n = matrix.size();
         int m = matrix[0].size();

        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                cnt++;
            }
        }

        if(cnt==0)
        return 0;


         int dp[n][m];


         
         int res = 1;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                  if(i==0 || j==0)
                  {
                     dp[i][j] = 1;
                     continue;
                  }
                  
                  if(matrix[i][j]==matrix[i-1][j] && matrix[i][j]==matrix[i-1][j-1] && matrix[i][j]==matrix[i][j-1])
                  {
                      dp[i][j] = 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                  }
                  else{
                      dp[i][j] = 1;
                  }

                  if(matrix[i][j]=='1')
                  {
                      res = max(res,dp[i][j]*dp[i][j]);
                  }
             }
         }

         return res;
    }
};
