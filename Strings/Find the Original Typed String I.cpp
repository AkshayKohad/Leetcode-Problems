class Solution {
public:
    int possibleStringCount(string word) {

        int i=0;
        int n = word.size();
        int result = 0;
        while(i<n){
            int cnt = 0;
            int j=i;
            while(j<n && word[i]==word[j]){
                cnt++;
                j++;
            }
            i=j;
            result += cnt-1;
        }
        return result+1;
    }
};
