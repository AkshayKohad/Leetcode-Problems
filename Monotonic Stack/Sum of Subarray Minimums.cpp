class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev_min(n);
        vector<int>next_min(n);
        stack<int> st;

        // Previous Smaller (strictly smaller)
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            prev_min[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Smaller or Equal
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            next_min[i] = st.empty() ? n : st.top();
            st.push(i);
        }

       const int MOD = 1e9 + 7;
        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_min[i];
            long long right = next_min[i] - i;
            minSum = (minSum + 1LL * nums[i] * left % MOD * right) % MOD;
        }
        // other formula can be, if left and right is number of count current element is smaller to in left and right side each respectively, then 
        // total contribution = num[i]*(left + right + left*right + 1) (1 for it's own subaaray with only num[i])
        // for subarray with size 1, there max and min will be same so it will be negated, so they are not included

        return minSum;
    }
};
