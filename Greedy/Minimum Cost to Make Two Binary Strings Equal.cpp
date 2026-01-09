class Solution {
public:
    #define ll long long
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.length();
        ll total_changes = 0;
        ll cnt_s_0 = 0;
        ll cnt_s_1 = 0;
        ll cnt_t_0 = 0;
        ll cnt_t_1 = 0;

        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                total_changes++;

                if(s[i]=='0'){
                    cnt_s_0++;
                    cnt_t_1++;
                }else{
                    cnt_s_1++;
                    cnt_t_0++;
                }
            }
        }

        ll result1 = total_changes*flipCost;
        ll result2 = min(cnt_s_0,cnt_s_1)*swapCost + (abs(cnt_s_0-cnt_s_1)/2)*(swapCost+crossCost) + (abs(cnt_s_0-cnt_s_1)%2)*flipCost;
        ll result3 = min(cnt_s_0,cnt_s_1)*swapCost + abs(cnt_s_0-cnt_s_1)*flipCost;
        return min({result1,result2,result3});
    }
};
