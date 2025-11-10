class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int result = 0;

        int n = nums.size();
        for(int i=0;i<n;i++){
            int prev_val = -1;
            while(st.empty()==false && st.top()>nums[i]){
                

                if(prev_val != st.top() && st.top()!=0){
                    result++;
                    prev_val = st.top();
                }

                st.pop();
            }

            st.push(nums[i]);
        }

        int prev_val = -1;
        while(st.empty()==false){

                if(prev_val != st.top() && st.top()!=0){
                    result++;
                    prev_val = st.top();
                }

                st.pop();
        }

        return result;
    }
};
