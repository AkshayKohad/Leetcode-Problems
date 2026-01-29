class Solution {
public:
    int minAllOneMultiple(int k) {
        int val = 1;
        int prev_val = 0;
        while(k>val){
            prev_val = val;
            val = val*10 + 1;
        }

        if(k==val)return to_string(val).length();

        if(val%k==0)return to_string(val).length();

        unordered_set<int>st;
        int result = to_string(val).length();
        int min_len = result;
         
        while(st.find(val%k)==st.end()){
            if(val%k==0)return result;
            st.insert(val%k);
            string s = to_string(val%k);
            
            int len = s.length();
            int req_len = 0;
           
            
            string new_s = s;
            while(stoi(new_s)<k){
                new_s.push_back('1');
                req_len++;
            }
            result += req_len;
            
            val = stoi(new_s);
        }
        return -1;
    }
};
