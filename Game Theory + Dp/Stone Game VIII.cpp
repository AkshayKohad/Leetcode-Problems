class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>prefix_stones(n);
        prefix_stones[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix_stones[i] = prefix_stones[i-1] + stones[i];
        }

        vector<int>dp(n,INT_MIN);
        int res = prefix_stones[n-1];
        dp[n-1] = prefix_stones[n-1];
        for(int i=n-2;i>=1;i--){
            dp[i] = max(res,prefix_stones[i]-res);
            res = max(res,dp[i]);
        }

        return res;
    }
};
