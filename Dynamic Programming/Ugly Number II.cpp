class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
		dp[0] = 0;
		dp[1] = 1;

		int p2 = 1;
		int p3 = 1;
		int p5 = 1;

		for(int i=2;i<=n;i++)
		{
			dp[i] = min({2*dp[p2],3*dp[p3],5*dp[p5]});
			if(dp[i] == 2*dp[p2])
			p2++;

			if(dp[i] == 3*dp[p3])
			p3++;

			if(dp[i] == 5*dp[p5])
			p5++;
		}
return dp[n];
    }
};
