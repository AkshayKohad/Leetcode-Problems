class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string res = "";
        int res_len = n+1;
        int i=0;
        int j=0;
        int cnt_1 = 0;
       
        while(j<n){
            if(s[j]=='1'){
                cnt_1++;
            }
            j++;
            while(i<=j && cnt_1>k){
                if(s[i]=='1'){
                    cnt_1--;
                }
                i++;
            }
            while(i<=j && cnt_1==k && s[i]!='1'){
                i++;
            }

            
            if(cnt_1==k){
                if(res_len > j-i){
                    res_len = j-i;
                    res = s.substr(i,j-i);
                }else if(res_len == j-i){
                    string cur = s.substr(i,j-i);
                    if(res>cur){
                        res = cur;
                    }
                }
            }
            
        }

        return res;
    }
};
