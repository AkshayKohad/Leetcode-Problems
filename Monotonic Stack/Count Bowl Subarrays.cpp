class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>nextGreater(n);
        vector<int>previousGreater(n);

        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(st.empty()){
                nextGreater[i] = -1;
            }
            else{
                if(st.top()==i+1){
                    nextGreater[i] = -1;
                }else{
                    nextGreater[i] = st.top();
                }
            }
            st.push(i);
        }

        while(st.empty()==false)st.pop();
        for(int i=0;i<n;i++){
            while(st.empty()==false && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(st.empty())previousGreater[i] = -1;
            else{
                if(st.top()==i-1){
                    previousGreater[i] = -1;
                }else{
                    previousGreater[i] = st.top();
                }
            }
            st.push(i);
        }

        int result = 0;
        for(int i=0;i<n;i++){
            if(previousGreater[i]!=-1)result++;
            if(nextGreater[i]!=-1)result++;
        }

        return result;
    }
};
