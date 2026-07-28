class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq_char(26,0);
        int n = s.length();
        for(int i=0;i<n;i++){
            freq_char[s[i]-'a']++;
        }
        int start = 0;
        int end = n-1;
        for(int i=0;i<26;i++){
            if(freq_char[i]%2){
                int middle = n/2;
                s[middle] = i+'a';
                freq_char[i]--;
            }

            while(freq_char[i]>0){
                s[start] = i+'a';
                s[end] = i+'a';
                start++;
                end--;
                freq_char[i]-=2; 
            }
        }
        return s;
    }
};
