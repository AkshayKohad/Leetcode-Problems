class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        stack<int>st;
        int n = target.size();

        int result = 0;

        for(int i=0;i<n;i++){
            if(st.empty()==true){
                st.push(target[i]);
                continue;
            }

            if(st.top()>= target[i]){
                st.push(target[i]);
                continue;
            }
            
            int val =  st.top();
            
            int last_val = st.top();

            while(st.empty()==false){
                last_val = st.top();
                st.pop();
            }
            st.push(target[i]);
            result += last_val-val;

        }

        int last_val = 0;
        while(st.empty()==false){
            last_val = st.top();
            st.pop();
        }
        
        result += last_val;

        return result;
    }
};
