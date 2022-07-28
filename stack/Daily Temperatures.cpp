class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        stack<int>st;
        
        vector<int>res(n,0);
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(st.empty()==false && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            
            if(st.empty()==true)
            {
                res[i] = 0;
                st.push(i);
            }
            
            else{
                res[i] = st.top()-i;
                
                st.push(i);
            }
        }
        
        return res;
    }
};
