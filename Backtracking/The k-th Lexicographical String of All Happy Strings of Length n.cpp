class Solution {
public:
    void solve(int i,int &n,vector<string>&result,string cur_string){
        if(i==n){
            result.push_back(cur_string);
            return;
        }

        for(char ch='a';ch<='c';ch++){
            if(cur_string.length()>0 && cur_string.back()==ch)continue;

            solve(i+1,n,result,cur_string + ch);
        }
    }
    string getHappyString(int n, int k) {
        vector<string>result;
        string cur_string = "";
        solve(0,n,result,cur_string);

        if(result.size()<k)return "";

        return result[k-1];
    }
};
