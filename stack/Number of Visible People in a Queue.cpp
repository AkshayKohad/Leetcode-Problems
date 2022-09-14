class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>res(n,0);
        
        
        stack<int>st;
        
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            int count = 0;
            
            while(st.empty()==false && st.top()<heights[i])
            {
                count++;
                st.pop();
            }
            
            
            res[i] = count;
            
            if(st.empty()==false)
            {
                res[i]++;
            }
            
            st.push(heights[i]);
        }
        
        return res;
    }
    
};
