class Solution {
public:
    // dp[pos][isZero][even_sum][odd_sum][parity]
    // parity: 0 = odd position, 1 = even position
    long long dp[16][2][2][136][136][2];
    bool vis[16][2][2][136][136][2];

    long long solve(int i, int n, int isZero, int isLimit,
                    int even_sum, int odd_sum,
                    int parity,
                    string &num) {

        if (i == n) {
            if (isZero) return 0;           // at least two digits
            return (even_sum == odd_sum);
        }

        if (vis[i][isLimit][isZero][even_sum][odd_sum][parity])
            return dp[i][isLimit][isZero][even_sum][odd_sum][parity];

        char limit = isLimit ? num[i] : '9';
        long long res = 0;

        for (char c = '0'; c <= limit; c++) {
            int d = c - '0';
            int nextLimit = (isLimit && c == limit);

            // Still leading zeros
            if (isZero && c == '0') {
                res += solve(i + 1, n,1, nextLimit,even_sum, odd_sum,parity,num);
            }
            // First non-zero digit → MUST be odd position
            else if (isZero) {
                res += solve(i + 1, n,0, nextLimit,even_sum,odd_sum + d,1,num);
            }
            // Normal digit
            else {
                if (parity == 0) { // odd position
                    res += solve(i + 1, n,0, nextLimit,even_sum,odd_sum + d,1,num);
                } else {            // even position
                    res += solve(i + 1, n,0, nextLimit,even_sum + d,odd_sum,0,num);
                }
            }
        }

        
        vis[i][isLimit][isZero][even_sum][odd_sum][parity] = true;
        dp[i][isLimit][isZero][even_sum][odd_sum][parity] = res;
        

        return res;
    }

    long long countUpTo(long long x) {
        if (x <= 0) return 0;
        string s = to_string(x);
        int n = s.size();
        memset(vis, false, sizeof(vis));
        return solve(0, n, 1, 1, 0, 0, 0, s);
    }

    long long countBalanced(long long low, long long high) {
        return countUpTo(high) - countUpTo(low - 1);
    }
};

