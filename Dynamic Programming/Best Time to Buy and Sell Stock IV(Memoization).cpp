class Solution {
public:
    
    int solve(int n,int k,vector<int>&a,vector<vector<int>>&memo)
{
	if(k==0)
	return 0;

	if(n==0)
	return 0;

    if(memo[n][k]!=-1)
	return memo[n][k];

   int res = solve(n-1,k,a,memo);
   
	for(int i=n-2;i>=0;i--)
	{
       res = max(res,solve(i,k-1,a,memo) + a[n-1]-a[i]);

	}
    memo[n][k] = res;
	return memo[n][k];
}
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
       vector<vector<int>>memo(n+1,vector<int>(k+1,-1));
		return solve(n,k,a,memo);
		
		
    }
};
