class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = s;
        stack<int>st;

        for(int i=0;i<s.length();i++){
            if(s[i] == ')' && st.empty()==false && s[st.top()] == '('){
                st.pop();
            }else if(s[i]=='(' || s[i]==')'){
                st.push(i);
            }
        }

        while(st.empty()==false){
            int ind = st.top();
            st.pop();
            res[ind] = ' ';
        }
        res.erase(remove(res.begin(),res.end(),' '),res.end());
        return res;
    }
};
