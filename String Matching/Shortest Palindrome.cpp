class Solution {
public:
    string shortestPalindrome(string s) {
        string original = s;
        string str = s;
        str.push_back('*');

        reverse(s.begin(),s.end());

        str = str + s;
        
        int n = str.length();

        vector<int>lps(n,0);

        int i=0;
        int j=1;

        while(j<str.length()){
            if(str[i]==str[j]){
                lps[j] = i+1;
                i++;
                j++;
            }
           

            else if(str[i]!=str[j]){
                if(i>0)
                    i = lps[i-1];

                else{
                    lps[j] = 0;
                    j++;
                }    

            }
        }

        int diff = original.length()-lps[n-1];

        original = s.substr(0,diff) + original;
        return original;
    }
};
