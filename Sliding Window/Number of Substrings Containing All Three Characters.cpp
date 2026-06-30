class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;

        int i=0;
        int j=0;
        int result = 0;
        while(j<n){
            if(s[j]=='a')cnt_a++;
            else if(s[j]=='b')cnt_b++;
            else cnt_c++;
            
            while(i<=j && cnt_a>0 && cnt_b>0 && cnt_c>0){
                result += n-j;
                if(s[i]=='a')cnt_a--;
                else if(s[i]=='b')cnt_b--;
                else cnt_c--;
                i++;
            }
            j++;
        }

        return result;
    }
};
