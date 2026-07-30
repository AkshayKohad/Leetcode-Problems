class Solution {
public:
    void solve(int i,int open,int closed,string &s,int &res,string &temp,set<string>&st){
        if(i==s.length()){
            if(closed != open)return;
            if(temp.size()==res){
                st.insert(temp);
            }else if(temp.size()>res){
                res = temp.size();
                st.clear();
                st.insert(temp);
            }

            return;
        }
        
        if(s[i]!='(' && s[i]!=')'){
                temp.push_back(s[i]);
                solve(i+1,open,closed,s,res,temp,st);
                temp.pop_back();
        }else{
                solve(i+1,open,closed,s,res,temp,st);
                if(open > closed){
                    char ch = s[i];
                    temp.push_back(ch);
                    if(ch == '('){
                        solve(i+1,open+1,closed,s,res,temp,st);
                    }else{
                        solve(i+1,open,closed+1,s,res,temp,st);
                    }
                    temp.pop_back();
                }else{
                    char ch = s[i];
                    if(ch == ')')solve(i+1,open,closed,s,res,temp,st);
                    else{
                        temp.push_back(ch);
                        solve(i+1,open+1,closed,s,res,temp,st);
                        temp.pop_back();
                    }
                }
            }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int res = 0;
        string temp;
        set<string>st;
        solve(0,0,0,s,res,temp,st);

        vector<string>result;
        for(auto str : st){
            result.push_back(str);
        }
        return result;
    }
};
