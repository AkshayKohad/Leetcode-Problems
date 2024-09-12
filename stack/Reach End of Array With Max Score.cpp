class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>next_greater(n);
        stack<int>st; 
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty()==false && nums[st.top()]<=nums[i])
            {
                st.pop();
            }

            if(st.empty()==false)
            {
                next_greater[i]=st.top();
            }
            else{
                next_greater[i]=-1;
            }
           st.push(i);
        }

        long long res = 0;
        int i=0;

        while(i<n)
        {
            int ind = next_greater[i];

            if(ind==-1)
            {
                res +=(long long)(n-1-i)*nums[i];
                break;
            }
            else{
                res +=(long long)(ind-i)*nums[i];
                i = ind;
            }
        }

        return res;
    }
};
