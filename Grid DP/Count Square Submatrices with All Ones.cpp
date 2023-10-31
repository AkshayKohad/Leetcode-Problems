class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=1;
                    continue;
                }

                if(matrix[i][j]==matrix[i-1][j] && matrix[i][j]==matrix[i][j-1] && matrix[i][j]==matrix[i-1][j-1])
                {
                    dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }

                else{
                    dp[i][j] = 1;
                }

            }
        }

      int res = 0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
                if(matrix[i][j]==1)
                {
                    int val = dp[i][j];

                    res += val;

                }
           }
       }

       return res;   
    }
};
