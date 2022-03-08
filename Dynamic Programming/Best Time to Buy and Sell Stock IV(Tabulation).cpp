class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        int dp[n+1][k+1];
   for(int i=0;i<=n;i++)
   dp[i][0] = 0;

   for(int i=0;i<=k;i++)
   dp[0][i] = 0;

   for(int i=1;i<=n;i++)
   {
	   for(int j=1;j<=k;j++)
	   {
		   int res = dp[i-1][j];

		   for(int l=i-2;l>=0;l--)
		   {
              res = max(res,dp[l][j-1] + a[i-1]-a[l]);
		   }

		   dp[i][j] = res;
	   }
   }
		
		return dp[n][k];
    }
};
