class Solution {
public:
    static const int mod = 1e9 + 7;

    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();

        unordered_map<int, long long> need1, need2;

        int px = 0;

        // Before starting: we need target1 from prefix 0
        need1[0] = 1;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            px ^= nums[i];

            long long ways1 = need1[px ^ target1]; // finish target1 segment
            long long ways2 = need2[px ^ target2]; // finish target2 segment

            // If we finished target1 → next expect target2
            need2[px] = (need2[px] + ways1) % mod;

            // If we finished target2 → next expect target1
            need1[px] = (need1[px] + ways2) % mod;

            // Count complete partitions ending at n
            if (i == n - 1) {
                ans = (ways1 + ways2) % mod;
            }
        }

        return ans;
    }
};
