class Solution {
public:
    #define ll long long
    const ll INF = 1e18;

    ll solveLinear(vector<ll>& cost, int start, int end, int k) {
        int n = cost.size();
        vector<vector<ll>> dp(n+2, vector<ll>(k+1, INF));

        for(int i = 0; i <= n+1; i++) dp[i][0] = 0;

        for(int i = end-1; i >= start; i--) {
            for(int j = 1; j <= k; j++) {
                ll skip = dp[i+1][j];
                ll take = cost[i] + dp[i+2][j-1];
                dp[i][j] = min(skip, take);
            }
        }

        return dp[start][k];
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> cost(n, 0);
        for(int i = 0; i < n; i++) {
            int maxi = max(nums[(i-1+n)%n], nums[(i+1)%n]);
            if(maxi >= nums[i]) {
                cost[i] = maxi - nums[i] + 1;
            }
        }

        // Case 1: take from [0 ... n-2]
        ll val1 = solveLinear(cost, 0, n-1, k);

        // Case 2: take from [1 ... n-1]
        ll val2 = solveLinear(cost, 1, n, k);

        ll ans = min(val1, val2);
        return (ans >= INF ? -1 : ans);
    }
};
