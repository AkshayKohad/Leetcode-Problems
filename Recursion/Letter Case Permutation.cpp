class Solution {
public:

    void solve(string &s,int i,vector<string>&result)
    {
        if(i==s.length())
        {
           result.push_back(s);
           return;
        }

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            solve(s,i+1,result);

            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
                solve(s,i+1,result);
                s[i] = toupper(s[i]);
            }

            else if(islower(s[i]))
            {
                 s[i] = toupper(s[i]);
                 solve(s,i+1,result);
                 s[i] = tolower(s[i]);   
            }

        }

        else{
            solve(s,i+1,result);
        }


    }
    vector<string> letterCasePermutation(string s) {
        vector<string>result;
        solve(s,0,result);
        return result;
    }
};
