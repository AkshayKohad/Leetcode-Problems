class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<long long> st;

        long long result = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            st.insert(nums[j]);

            while (!st.empty() && 
                   (*st.rbegin() - *st.begin()) * (j - i + 1) > k) {
                st.erase(st.find(nums[i]));
                i++;
            }

            result += (j - i + 1);
        }

        return result;
    }
};
