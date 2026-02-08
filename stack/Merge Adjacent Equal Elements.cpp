class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>result;
        stack<long long>st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            long long cur = nums[i];
            while(st.empty()==false && st.top()==cur){
                cur += st.top();
                st.pop();
            }

            st.push(cur);
        }

        result.assign(st.size(),0);
        n = st.size();
        for(int i=n-1;i>=0;i--){
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
