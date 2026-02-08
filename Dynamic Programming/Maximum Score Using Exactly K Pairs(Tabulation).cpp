class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        int n = nums1.size();
        int m = nums2.size();

        const long long NEG = LLONG_MIN;

        // dp[i][j][k]
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(m + 1, vector<long long>(K + 1, NEG))
        );

        // base: k = 0 → score = 0
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j][0] = 0;

        // fill from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int k = 1; k <= K; k++) {

                    long long best = NEG;

                    // take pair
                    if (dp[i + 1][j + 1][k - 1] != NEG) {
                        best = max(best,
                                   (long long)nums1[i] * nums2[j]
                                   + dp[i + 1][j + 1][k - 1]);
                    }

                    // skip nums1[i]
                    best = max(best, dp[i + 1][j][k]);

                    // skip nums2[j]
                    best = max(best, dp[i][j + 1][k]);

                    dp[i][j][k] = best;
                }
            }
        }

        return dp[0][0][K];
    }
};
