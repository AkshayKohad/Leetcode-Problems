class Solution {
public:
    #define ll long long
    #define mod 1000000007

   int possibleStringCount(string word, int k) {
        // Step 1: Count frequencies of consecutive identical characters
        vector<ll> freq_chars;
        ll n = word.length();
        ll i = 0;
        while(i < n){
            ll j = i;
            ll cnt = 0;
            while(j < n && word[i] == word[j]){
                j++;
                cnt++;
            }
            freq_chars.push_back(cnt);
            i = j;
        }

        // Step 2: Calculate total number of words (product of frequencies modulo mod)
        ll total_number_of_words = 1;
        for(auto cnt : freq_chars){
            total_number_of_words = (total_number_of_words * cnt) % mod;
        }

        // If the number of distinct character blocks is >= k, return total_number_of_words
        if(freq_chars.size() >= k) return total_number_of_words;

        ll m = freq_chars.size();
        
        // Step 3: Initialize DP table
        // dp[i][j] = number of ways using first i blocks with exactly j removals
        // We'll use j up to k-1 because we want at least k changes
        // Initialize a (m+1) x k table with 0s
        vector<vector<ll>> dp(m + 1, vector<ll>(k, 0));
        dp[0][0] = 1; // Base case: 0 blocks, 0 removals

        // Fill DP table
        for(ll block = 1; block <= m; block++) {
            // Compute prefix sums for the previous block
            vector<ll> prefix_sum(k + 1, 0);
            for(ll w = 0; w < k; w++) {
                prefix_sum[w + 1] = (prefix_sum[w] + dp[block - 1][w]) % mod;
            }

            // Update current DP state
            for(ll j = 0; j < k; j++) {
                // Calculate the number of ways to reach j removals by considering
                // up to freq_chars[block - 1] removals in this block
                ll min_remove = min(j, freq_chars[block - 1]);
                dp[block][j] = (prefix_sum[j] - (j >= min_remove ? prefix_sum[j - min_remove] : 0)) % mod;
                if(dp[block][j] < 0) dp[block][j] += mod; // Ensure non-negative
            }
        }

        // Step 4: Calculate the number of unwanted cases (less than k removals)
        ll result_remove = 0;
        for(ll j = 0; j < k; j++) {
            result_remove = (result_remove + dp[m][j]) % mod;
        }

        // Step 5: Calculate the final result
        ll final_result = (total_number_of_words - result_remove) % mod;
        if(final_result < 0) final_result += mod; // Ensure non-negative

        return final_result;
    }
};
