class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev_min(n);
        vector<int>next_min(n);
        vector<int>prev_max(n);
        vector<int>next_max(n);

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

        // Previous Greater (strictly greater)
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            prev_max[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Greater or Equal
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            next_max[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_min[i];
            long long right = next_min[i] - i;
            minSum += 1LL * nums[i] * left * right;
        }

        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_max[i];
            long long right = next_max[i] - i;
            maxSum += 1LL * nums[i] * left * right;
        }

        // for subarray with size 1, there max and min will be same so it will be negated, so they are not included

        return maxSum - minSum;
    }
};

// eg for [1,2,3] (left,right)
// max contri of 1 (0,0) -> 1
// max contri of 2 (1,0) -> 2*(left + right + left*right) + 2 -> 4
// max contri of 3 (2,0) -> 3*(left + right + left*right) + 3 -> 9

// max contribution - 14

// min contri of 1 (0,2) -> 1*(left + right + left*right) + 1 -> 3
// min contri of 2 (0,1) -> 2*(left + right + left*right) + 2 -> 4
// min contri of 3 (0,0) -> 3 -> 3

// min contri 10
// so answer is max_contri - min_contri
