class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        int n = s.length();
        int i=0;
        int res_vowel = -1;
        while(i<n){
            string temp;
            int temp_vowel = 0;
            int j=i;
            while(i<n && s[i]!=' '){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')temp_vowel++;
                i++;
            }
            
            if(res_vowel == -1){
                res_vowel = temp_vowel;
            }else if(res_vowel == temp_vowel){
                reverse(s.begin()+j,s.begin()+i);
            }

            if(s[i]==' ')i++;            
        }
        return s;
    }
};
