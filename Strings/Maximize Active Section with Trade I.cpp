class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i=0;
        int n = s.length();
        int cnt_1 = 0;
        vector<int>cnt_zeroes;
        while(i<n){
            int j=i;
            if(j<n && s[j]=='0'){
                while(j<n && s[j]=='0'){
                    j++;
                }
                cnt_zeroes.push_back(j-i);
                i=j;
            }else if(j<n && s[j]=='1'){
                j++;
                cnt_1++;
            }
            i=j;
        }

        if(cnt_zeroes.size()<=1)return cnt_1;

        int max_zero_cnt = 0;
        for(int i=0;i<cnt_zeroes.size()-1;i++){
            max_zero_cnt = max(max_zero_cnt, cnt_zeroes[i]+cnt_zeroes[i+1]);
        }
        return cnt_1 + max_zero_cnt;
    }
};
