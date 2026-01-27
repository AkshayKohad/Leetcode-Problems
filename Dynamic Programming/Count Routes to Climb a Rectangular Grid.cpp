class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int d) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long> (m, 0));
        vector<long long> pref(m, 0);
        const int M = 1e9 + 7;
        for(int i=0;i<m;i++) {
            if(grid[n-1][i] == '.') {
                dp[n-1][i] = 1;
            }
        }
        for(int i=0;i<m;i++){
            if(i == 0) pref[i] = dp[n-1][i];
            else pref[i] = pref[i-1] + dp[n-1][i];
            pref[i] %= M;
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i] != '.') continue;
            int j1 = max(-1, i - d - 1), j2 = min(m-1, i + d);
            int extra = dp[n-1][i];
            if(j1>=0) dp[n-1][i] += (pref[j2] - pref[j1] + M) % M;
            else dp[n-1][i] += pref[j2];
            dp[n-1][i] %= M;
            dp[n-1][i] -= extra;
            dp[n-1][i] += M;
            dp[n-1][i] %= M;
        }
        for(int i=0;i<m;i++){
            if(i == 0) pref[i] = dp[n-1][i];
            else pref[i] = pref[i-1] + dp[n-1][i];
            pref[i] %= M;
        }
        int lim = 0;
        if(d != 0) lim = (int)sqrt(d*d - 1);
        // cout<<lim<<endl;
        for(int i=0;i<m;i++) cout<<dp[n-1][i]<<" ";
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(grid[i][j] != '.') continue;
                int j1 = max(-1, j - lim - 1), j2 = min(m-1, j + lim);
                if(j1>=0) dp[i][j] += (pref[j2] - pref[j1] + M) % M;
                else dp[i][j] += pref[j2];
                dp[i][j] %= M;
            }
            for(int j=0;j<m;j++){
                if(j == 0) pref[j] = dp[i][j];
                else pref[j] = pref[j-1] + dp[i][j];
                pref[j] %= M;
            }
            for(int j=0;j<m;j++){
                if(grid[i][j] != '.') continue;
                int j1 = max(-1, j - d - 1), j2 = min(m-1, j + d);
                int extra = dp[i][j];
                if(j1>=0) dp[i][j] += (pref[j2] - pref[j1] + M) % M;
                else dp[i][j] += pref[j2];
                dp[i][j] %= M;

                dp[i][j] -= extra;
                dp[i][j] += M;
                dp[i][j] %= M;
            }
            for(int j=0;j<m;j++){
                if(j == 0) pref[j] = dp[i][j];
                else pref[j] = pref[j-1] + dp[i][j];
                pref[j] %= M;
            }
        }
        return pref[m-1];
    }
};
