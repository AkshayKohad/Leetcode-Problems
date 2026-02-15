class Solution {
public:
    int solve2(string s,int left,int right){
        int len = 0;
        int n = s.length();
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                len += (left == right ? 1 : 2);
                left--;
                right++;
            } else {
                break;
            }
        }
        return len;
    }
    int solve(string s,int left,int right) {
        int n = s.length();
        int removed = 0;
        int len = 0;
        int ans = 0;
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                len += (left == right ? 1 : 2);
                left--;
                right++;
            } else {
                if (removed) break;

                if (left-1 >= 0 && s[left-1] == s[right]) {
                    removed = 1;
                    
                    ans = max(ans,solve2(s,left-1,right));
                }
                if (right+1 < n && s[left] == s[right+1]) {
                    removed = 1;
                    
                    ans = max(ans,solve2(s,left,right+1));
                }
                break;
            }
        }
        if(removed == 0){
            if(left>=0 || right<n)return ans+len+1;
            else return 0;
        }else{
            return ans+len+1;
        }          
    }

    int almostPalindromic(string s) {
        int n = s.length();
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, solve(s, i, i)); 
            result = max(result, solve(s, i, i + 1));   
        }
        return result;
    }
};
